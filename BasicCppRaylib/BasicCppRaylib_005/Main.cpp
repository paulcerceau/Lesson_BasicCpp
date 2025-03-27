#include "raylib.h"

#include "Ball.h"
#include "Paddle.h"
#include "SceneManager.h"
#include "Utilities.h"

#include <iostream>
#include <vector>

using std::vector;

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------


//----------------------------------------------------------------------------------
// Const Declaration
//----------------------------------------------------------------------------------

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;
const char* WINDOW_NAME = "Basic C++ with Raylib";

const float BALL_X_OFFSET = 200.0f;
const float BALL_BASE_SPEED = 4.0f;

const float PADDLE_BASE_WIDTH = 10.0f;
const float PADDLE_BASE_HEIGHT = 100.0f;
const float PADDLE_MAX_SPEED = 6.0f;
const float PADDLE_DECELERATION_FACTOR = 0.95f;

const int WINNING_SCORE = 10;
const float SCORE_TEXT_SIZE = 50.0f;

//----------------------------------------------------------------------------------
// Variables Declaration
//----------------------------------------------------------------------------------

Font font = { 0 };

SceneManager sceneManager;

bool gameOver = false;
bool pause = false;

Ball ball;
Paddle leftPaddle;
Paddle rightPaddle;

int leftScore = 0;
int rightScore = 0;

//----------------------------------------------------------------------------------
// Global Functions Declaration
//----------------------------------------------------------------------------------

void InitGame();
void ResetGame();
void Update();
void UpdateDrawFrame();
void DrawBackgroundUI();
void Draw();

//----------------------------------------------------------------------------------
// Game-Specific Functions Declaration
//----------------------------------------------------------------------------------

void ScoreGoal(bool scoredByLeft);

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------

int main() {
    //v Initialization ===============================================
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);

    InitAudioDevice();

    InitGame();

    SetTargetFPS(60);

    //^ Initialization ===============================================
    //v Main game loop ===============================================
    while (!WindowShouldClose())
    {
        UpdateDrawFrame();
    }

    //^ Main game loop ===============================================
    //v De-Initialization ============================================
    CloseAudioDevice();

    CloseWindow();

    //^ De-Initialization ============================================

    return 0;
}

//----------------------------------------------------------------------------------
// Global Functions Definition
//----------------------------------------------------------------------------------

void InitGame()
{
	// -- SCENE MANAGER --
    sceneManager.SetCurrentState(SceneState::Menu);

    // -- FONT --
    font = LoadFont("../resources/fonts/alagard.png");

    ResetGame();
}

void ResetGame()
{
    // -- BALL --
    Vector2 startPosition{ SCREEN_WIDTH / 2.0f - BALL_X_OFFSET, SCREEN_HEIGHT / 2.0f };
    Vector2 speed{ BALL_BASE_SPEED, BALL_BASE_SPEED };

    ball.Init(startPosition, speed, 10.0f, BLUE);

    // -- PADDLES --
    Vector2 leftPaddlePosition{ 10.0f, 10.0f };
    Vector2 leftPaddleSpeed{ 0.0f, 0.0f };

    leftPaddle.Init(leftPaddlePosition, leftPaddleSpeed, PADDLE_BASE_WIDTH, PADDLE_BASE_HEIGHT, DARKBLUE);

    Vector2 rightpaddlePosition{ SCREEN_WIDTH - (10.0f + PADDLE_BASE_WIDTH), 10.0f };
    Vector2 rightpaddleSpeed{ 0.0f, 0.0f };

    rightPaddle.Init(rightpaddlePosition, rightpaddleSpeed, PADDLE_BASE_WIDTH, PADDLE_BASE_HEIGHT, DARKBLUE);

    // -- SCORES --
    leftScore = 0;
    rightScore = 0;

}

void UpdateDrawFrame()
{
    //v Update =======================================================
    Update();

    //^ Update =======================================================
    //v Draw =========================================================
    BeginDrawing();
    ClearBackground(SKYBLUE);

    DrawBackgroundUI();
    Draw();

    EndDrawing();

    //^ Draw =========================================================
}

void Update()
{
	if (sceneManager.GetCurrentState() == SceneState::Menu)
	{
		if (IsKeyPressed(KEY_ENTER))
		{
            ResetGame();
			sceneManager.SetCurrentState(SceneState::TwoPlayersGamemode);
		}
	}
	else if (sceneManager.GetCurrentState() == SceneState::TwoPlayersGamemode)
    {
        if (IsKeyPressed('P')) 
        {
            pause = !pause;
        }
		else if (IsKeyPressed('M'))
		{
			sceneManager.SetCurrentState(SceneState::Menu);
		}

        if (!pause)
        {
            //v Ball =========================================================
            ball.Update();

            // Ball horizontal walls collision
            if (ball.GetPosition().y >= SCREEN_HEIGHT || ball.GetPosition().y <= 0)
            {
                ball.SetSpeed(Vector2{ ball.GetSpeed().x, -ball.GetSpeed().y });
            }

            // Ball paddle collision
            if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), leftPaddle.GetPaddleRectangle()) ||
                CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), rightPaddle.GetPaddleRectangle()))
            {
                ball.SetSpeed(Vector2{ -ball.GetSpeed().x, ball.GetSpeed().y });
            }

            // Ball out of vertical bounds
            if (ball.GetPosition().x >= SCREEN_WIDTH)
            {
				ScoreGoal(true);
            }
            else if (ball.GetPosition().x <= 0)
            {
				ScoreGoal(false);
            }

            //^ Ball =========================================================
            //v Paddles ======================================================
            // Left paddle movement
            if (IsKeyDown('W'))
            {
                leftPaddle.SetSpeed(Vector2{ 0.0f, -PADDLE_MAX_SPEED });
            }
            else if (IsKeyDown('S'))
            {
                leftPaddle.SetSpeed(Vector2{ 0.0f, PADDLE_MAX_SPEED });
            }
            else
            {
                leftPaddle.SetSpeed(Vector2{ 0.0f, leftPaddle.GetSpeed().y * PADDLE_DECELERATION_FACTOR });
            }

            // Left paddle collisions
            if (leftPaddle.GetPosition().y <= 0)
            {
                leftPaddle.SetPosition(Vector2{ leftPaddle.GetPosition().x, 0 });
            }
            else if (leftPaddle.GetPosition().y + leftPaddle.GetHeight() >= SCREEN_HEIGHT)
            {
                leftPaddle.SetPosition(Vector2{ leftPaddle.GetPosition().x, SCREEN_HEIGHT - leftPaddle.GetHeight() });
            }

            leftPaddle.Update();

            // Right paddle movement
            if (IsKeyDown(KEY_UP))
            {
                rightPaddle.SetSpeed(Vector2{ 0.0f, -PADDLE_MAX_SPEED });
            }
            else if (IsKeyDown(KEY_DOWN))
            {
                rightPaddle.SetSpeed(Vector2{ 0.0f, PADDLE_MAX_SPEED });
            }
            else
            {
                rightPaddle.SetSpeed(Vector2{ 0.0f, rightPaddle.GetSpeed().y * PADDLE_DECELERATION_FACTOR });
            }

            // Right paddle collisions
            if (rightPaddle.GetPosition().y <= 0)
            {
                rightPaddle.SetPosition(Vector2{ rightPaddle.GetPosition().x, 0 });
            }
            else if (rightPaddle.GetPosition().y + rightPaddle.GetHeight() >= SCREEN_HEIGHT)
            {
                rightPaddle.SetPosition(Vector2{ rightPaddle.GetPosition().x, SCREEN_HEIGHT - rightPaddle.GetHeight() });
            }

            rightPaddle.Update();

            //^ Paddles ======================================================
        }
    }
	else if (sceneManager.GetCurrentState() == SceneState::Score)
	{
        if (IsKeyPressed('M'))
		{
			sceneManager.SetCurrentState(SceneState::Menu);
		}
        else if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
        {
			ResetGame();
            sceneManager.SetCurrentState(SceneState::TwoPlayersGamemode);
        }
	}
}

void DrawBackgroundUI()
{
    if (sceneManager.GetCurrentState() == SceneState::Menu)
    {
        const float screenVerticalMiddle = SCREEN_HEIGHT / 2.0f;

        Utils::DrawCenteredText("PONG", Vector2{ SCREEN_WIDTH / 2.0f, screenVerticalMiddle - 100.0f }, 50, WHITE);
        Utils::DrawCenteredText("Press Enter to start", Vector2{ SCREEN_WIDTH / 2.0f, screenVerticalMiddle }, 20, WHITE);
    }
    else if (sceneManager.GetCurrentState() == SceneState::TwoPlayersGamemode)
    {
        const float textOffset = 50.0f;

        Utils::DrawCenteredTextEx(font, TextFormat("%i", leftScore), Vector2{ SCREEN_WIDTH / 2.0f - textOffset, 50.0f }, SCORE_TEXT_SIZE, 0.0f, WHITE);
        Utils::DrawCenteredTextEx(font, TextFormat("%i", rightScore), Vector2{ SCREEN_WIDTH / 2.0f + textOffset, 50.0f }, SCORE_TEXT_SIZE, 0.0f, WHITE);
    }
    else if (sceneManager.GetCurrentState() == SceneState::Score)
    {
        const float screenVerticalMiddle = SCREEN_HEIGHT / 2.0f;
        const float textOffset = 50.0f;

        Utils::DrawCenteredTextEx(font, TextFormat("%i", leftScore), Vector2{ SCREEN_WIDTH / 2.0f - textOffset, 50.0f }, SCORE_TEXT_SIZE, 0.0f, WHITE);
        Utils::DrawCenteredTextEx(font, TextFormat("%i", rightScore), Vector2{ SCREEN_WIDTH / 2.0f + textOffset, 50.0f }, SCORE_TEXT_SIZE, 0.0f, WHITE);

		const char* winnerText = leftScore >= WINNING_SCORE ? "Left player wins!" : "Right player wins!";

        Utils::DrawCenteredText(winnerText, Vector2{ SCREEN_WIDTH / 2.0f, screenVerticalMiddle }, 40, WHITE);

        Utils::DrawCenteredText("Press Enter/Space to restart", Vector2{ SCREEN_WIDTH / 2.0f, screenVerticalMiddle + 100.0f }, 20, WHITE);
        Utils::DrawCenteredText("Press M to go back to the main menu", Vector2{ SCREEN_WIDTH / 2.0f, screenVerticalMiddle + 125.0f }, 20, WHITE);
    }
}

void Draw()
{
	if (sceneManager.GetCurrentState() == SceneState::TwoPlayersGamemode)
    {
        // Draw middle separator
        DrawRectangle(SCREEN_WIDTH / 2.0f, 0, 2, SCREEN_HEIGHT, WHITE);

        ball.Draw();

        leftPaddle.Draw();
        rightPaddle.Draw();
    }
}

//----------------------------------------------------------------------------------
// Game-Specific Functions Definition
//----------------------------------------------------------------------------------

void ScoreGoal(bool scoredByLeft)
{
    if (scoredByLeft)
    {
        leftScore++;

        // Reset ball
        ball.SetPosition(Vector2{ SCREEN_WIDTH / 2.0f - BALL_X_OFFSET, SCREEN_HEIGHT / 2.0f });
        ball.SetSpeed(Vector2{ BALL_BASE_SPEED, BALL_BASE_SPEED });

        if (leftScore >= WINNING_SCORE)
        {
            sceneManager.SetCurrentState(SceneState::Score);
        }
    }
    else
    {
        rightScore++;

        // Reset ball
        ball.SetPosition(Vector2{ SCREEN_WIDTH / 2.0f + BALL_X_OFFSET, SCREEN_HEIGHT / 2.0f });
        ball.SetSpeed(Vector2{ -BALL_BASE_SPEED, BALL_BASE_SPEED });

        if (rightScore >= WINNING_SCORE)
        {
            sceneManager.SetCurrentState(SceneState::Score);
        }
    }
}
