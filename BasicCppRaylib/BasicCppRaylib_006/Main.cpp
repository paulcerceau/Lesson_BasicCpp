#include "raylib.h"

#include "Ball.h"
#include "Consts.h"
#include "Paddle.h"
#include "SceneManager.h"
#include "Utilities.h"

#include <iostream>
#include <vector>

using std::vector;


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
    InitWindow(Consts::Window::WIDTH, Consts::Window::HEIGHT, Consts::Window::NAME);

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
    ball.Init();

    // -- PADDLES --
    Vector2 leftPaddlePosition{ 10.0f, 10.0f };
    Vector2 leftPaddleSpeed{ 0.0f, 0.0f };
	PaddleInputs leftPaddleInputs{ 'W', 'S' };

    leftPaddle.Init(leftPaddlePosition, leftPaddleSpeed, leftPaddleInputs);

    Vector2 rightpaddlePosition{ Consts::Window::WIDTH - (10.0f + Consts::Paddle::BASE_WIDTH), 10.0f };
    Vector2 rightpaddleSpeed{ 0.0f, 0.0f };
	PaddleInputs rightPaddleInputs{ KEY_UP, KEY_DOWN };

    rightPaddle.Init(rightpaddlePosition, rightpaddleSpeed, rightPaddleInputs);

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
    switch (sceneManager.GetCurrentState())
    {
        case SceneState::Menu:
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                ResetGame();
                sceneManager.SetCurrentState(SceneState::TwoPlayersGamemode);
            }

            break;
        }
        case SceneState::TwoPlayersGamemode:
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
				ball.HandlePaddleCollision(leftPaddle, true);
				ball.HandlePaddleCollision(rightPaddle, false);
                
                ball.Update();

                // Ball out of vertical bounds
                if (ball.GetPosition().x >= Consts::Window::WIDTH)
                {
                    ScoreGoal(true);
                }
                else if (ball.GetPosition().x <= 0)
                {
                    ScoreGoal(false);
                }

                //^ Ball =========================================================
                //v Paddles ======================================================
                leftPaddle.ProcessInputs();
                leftPaddle.Update();

                rightPaddle.ProcessInputs();
                rightPaddle.Update();

                //^ Paddles ======================================================
            }

            break;
        }
        case SceneState::Score:
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

            break;
        }
    }
}

void DrawBackgroundUI()
{
    switch (sceneManager.GetCurrentState())
    {
        case SceneState::Menu:
        {
            const float screenVerticalMiddle = Consts::Window::HEIGHT / 2.0f;

            Utils::DrawCenteredText("PONG", Vector2{ Consts::Window::WIDTH / 2.0f, screenVerticalMiddle - 100.0f }, 50, WHITE);
            Utils::DrawCenteredText("Press Enter to start", Vector2{ Consts::Window::WIDTH / 2.0f, screenVerticalMiddle }, 20, WHITE);

            break;
        }
        case SceneState::TwoPlayersGamemode:
        {
            const float textOffset = 50.0f;

            Utils::DrawCenteredTextEx(font, TextFormat("%i", leftScore), Vector2{ Consts::Window::WIDTH / 2.0f - textOffset, 50.0f }, Consts::Score::TEXT_SIZE, 0.0f, WHITE);
            Utils::DrawCenteredTextEx(font, TextFormat("%i", rightScore), Vector2{ Consts::Window::WIDTH / 2.0f + textOffset, 50.0f }, Consts::Score::TEXT_SIZE, 0.0f, WHITE);

            break;
        }
        case SceneState::Score:
        {
            const float screenVerticalMiddle = Consts::Window::HEIGHT / 2.0f;
            const float textOffset = 50.0f;

            Utils::DrawCenteredTextEx(font, TextFormat("%i", leftScore), Vector2{ Consts::Window::WIDTH / 2.0f - textOffset, 50.0f }, Consts::Score::TEXT_SIZE, 0.0f, WHITE);
            Utils::DrawCenteredTextEx(font, TextFormat("%i", rightScore), Vector2{ Consts::Window::WIDTH / 2.0f + textOffset, 50.0f }, Consts::Score::TEXT_SIZE, 0.0f, WHITE);

            const char* winnerText = leftScore >= Consts::Score::WINNING_SCORE ? "Left player wins!" : "Right player wins!";

            Utils::DrawCenteredText(winnerText, Vector2{ Consts::Window::WIDTH / 2.0f, screenVerticalMiddle }, 40, WHITE);

            Utils::DrawCenteredText("Press Enter/Space to restart", Vector2{ Consts::Window::WIDTH / 2.0f, screenVerticalMiddle + 100.0f }, 20, WHITE);
            Utils::DrawCenteredText("Press M to go back to the main menu", Vector2{ Consts::Window::WIDTH / 2.0f, screenVerticalMiddle + 125.0f }, 20, WHITE);

            break;
        }
    }
}

void Draw()
{
    switch (sceneManager.GetCurrentState())
    {
        case SceneState::TwoPlayersGamemode:
        {
            // Draw middle separator
            DrawRectangle(Consts::Window::WIDTH / 2.0f, 0, 2, Consts::Window::HEIGHT, WHITE);

            ball.Draw();

            leftPaddle.Draw();
            rightPaddle.Draw();

            break;
        }
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
        ball.SetPosition(Vector2{ Consts::Window::WIDTH / 2.0f - Consts::Ball::X_OFFSET, Consts::Window::HEIGHT / 2.0f });
        ball.SetDirectionAngleRad(PI / 4.0f);

        if (leftScore >= Consts::Score::WINNING_SCORE)
        {
            sceneManager.SetCurrentState(SceneState::Score);
        }
    }
    else
    {
        rightScore++;

        // Reset ball
        ball.SetPosition(Vector2{ Consts::Window::WIDTH / 2.0f + Consts::Ball::X_OFFSET, Consts::Window::HEIGHT / 2.0f });
        ball.SetDirectionAngleRad(3 * PI / 4.0f);

        if (rightScore >= Consts::Score::WINNING_SCORE)
        {
            sceneManager.SetCurrentState(SceneState::Score);
        }
    }
}
