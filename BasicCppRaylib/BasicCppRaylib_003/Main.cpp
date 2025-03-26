#include "raylib.h"

#include "Utilities.h"

#include "Ball.h"
#include "Paddle.h"

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

//----------------------------------------------------------------------------------
// Variables Declaration
//----------------------------------------------------------------------------------

Font font = { 0 };

bool gameOver = false;
bool pause = false;

Ball ball;
Paddle leftPaddle;
Paddle rightPaddle;

int leftScore = 0;
int rightScore = 0;

//----------------------------------------------------------------------------------
// Functions Declaration
//----------------------------------------------------------------------------------

void InitGame();
void Update();
void UpdateDrawFrame();
void DrawBackgroundUI();
void Draw();

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------

int main() {
    //v Initialization ===============================================
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);

    InitAudioDevice();      // Initialize audio device

    InitGame();

    SetTargetFPS(60);       // Set our game to run at 60 frames-per-second

    //^ Initialization ===============================================
    //v Main game loop ===============================================
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        UpdateDrawFrame();
    }

    //^ Main game loop ===============================================
    //v De-Initialization ============================================
    CloseAudioDevice();     // Close audio context

    CloseWindow();          // Close window and OpenGL context

    //^ De-Initialization ============================================

    return 0;
}

//----------------------------------------------------------------------------------
// Functions Definition
//----------------------------------------------------------------------------------

void InitGame()
{
    // -- FONT --
    font = LoadFont("../resources/fonts/alagard.png");

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

	// -- SCORE --
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
    if (!gameOver)
    {
        if (IsKeyPressed('P')) pause = !pause;

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
                leftScore++;

				// Reset ball
				ball.SetPosition(Vector2{ SCREEN_WIDTH / 2.0f - BALL_X_OFFSET, SCREEN_HEIGHT / 2.0f });
				ball.SetSpeed(Vector2{ BALL_BASE_SPEED, BALL_BASE_SPEED });
			}
            else if (ball.GetPosition().x <= 0)
            {
				rightScore++;

				// Reset ball
				ball.SetPosition(Vector2{ SCREEN_WIDTH / 2.0f + BALL_X_OFFSET, SCREEN_HEIGHT / 2.0f });
				ball.SetSpeed(Vector2{ -BALL_BASE_SPEED, BALL_BASE_SPEED });
            }

            //^ Ball =========================================================
			//v Paddles =========================================================
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

			rightPaddle.Update();
        }
    }
}

void DrawBackgroundUI()  
{  
	const float textOffset = 50.0f;

    Utils::DrawCenteredTextEx(font, TextFormat("%i", leftScore), Vector2{ SCREEN_WIDTH / 2.0f - textOffset, 50.0f }, 50.0f, 0.0f, WHITE);
    Utils::DrawCenteredTextEx(font, TextFormat("%i", rightScore), Vector2{ SCREEN_WIDTH / 2.0f + textOffset, 50.0f }, 50.0f, 0.0f, WHITE);
}

void Draw()
{
	// Draw middle separator
	DrawRectangle(SCREEN_WIDTH / 2.0f, 0, 2, SCREEN_HEIGHT, WHITE);
    
    ball.Draw();

	leftPaddle.Draw();
	rightPaddle.Draw();

}
