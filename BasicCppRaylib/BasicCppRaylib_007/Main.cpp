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

// -- FONTS --
Font font = { 0 };

// -- AUDIO --
Music music = { 0 };

Sound menuConfirm = { 0 };
Sound menuPause = { 0 };
Sound ballWallHitSound = { 0 };
Sound ballPaddleHitSound = { 0 };
Sound ballGoalSound = { 0 };

// -- TEXTURES --
Texture2D leftPaddeTexture = { 0 };
Texture2D rightPaddleTexture = { 0 };
Texture2D ballTexture = { 0 };

// -- GAME STATES --
SceneManager sceneManager;

bool gameOver = false;
bool pause = false;

// -- GAME OBJECTS --
Ball ball;
Paddle leftPaddle;
Paddle rightPaddle;

// -- SCORES --
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
void Unload();

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
    Unload();

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

    // -- AUDIO --
	music = LoadMusicStream("../resources/audio/A_Worthy_Challenge.wav");

	PlayMusicStream(music);
	SetMusicVolume(music, 0.25f);

	menuConfirm = LoadSound("../resources/audio/menu_Confirm.wav");
	SetSoundVolume(menuConfirm, 0.5f);
	menuPause = LoadSound("../resources/audio/menu_Pause.wav");
    ballWallHitSound = LoadSound("../resources/audio/ball_WallHit.wav");
    ballPaddleHitSound = LoadSound("../resources/audio/ball_PaddleHit.wav");
    ballGoalSound = LoadSound("../resources/audio/ball_Goal.wav");

	// -- TEXTURES --
	leftPaddeTexture = LoadTexture("../resources/textures/leftPaddle.png");
	rightPaddleTexture = LoadTexture("../resources/textures/rightPaddle.png");
	ballTexture = LoadTexture("../resources/textures/ball.png");

    ResetGame();
}

void ResetGame()
{
    // -- BALL --
    ball.Init();
	ball.SetTexture(&ballTexture);
	ball.SetSounds(BallSounds{ &ballWallHitSound, &ballPaddleHitSound, &ballGoalSound });

    // -- PADDLES --
    const Vector2 leftPaddlePosition{ 10.0f, 10.0f };
    const Vector2 leftPaddleSpeed{ 0.0f, 0.0f };
	const PaddleInputs leftPaddleInputs{ 'W', 'S' };

    leftPaddle.Init(leftPaddlePosition, leftPaddleSpeed, leftPaddleInputs);
	leftPaddle.SetTexture(&leftPaddeTexture);

    const Vector2 rightpaddlePosition{ Consts::Window::WIDTH - (10.0f + Consts::Paddle::BASE_WIDTH), 10.0f };
    const Vector2 rightpaddleSpeed{ 0.0f, 0.0f };
    const PaddleInputs rightPaddleInputs{ KEY_UP, KEY_DOWN };

    rightPaddle.Init(rightpaddlePosition, rightpaddleSpeed, rightPaddleInputs);
	rightPaddle.SetTexture(&rightPaddleTexture);

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
	UpdateMusicStream(music);

    switch (sceneManager.GetCurrentState())
    {
        case SceneState::Menu:
        {
            if (IsKeyPressed(KEY_ENTER))
            {
				PlaySound(menuConfirm);
                ResetGame();
                sceneManager.SetCurrentState(SceneState::TwoPlayersGamemode);
            }

            break;
        }
        case SceneState::TwoPlayersGamemode:
        {
            if (IsKeyPressed('P'))
            {
				PlaySound(menuPause);

                pause = !pause;

				pause ? PauseMusicStream(music) : ResumeMusicStream(music);
            }
            else if (IsKeyPressed('M'))
            {
                PlaySound(menuConfirm);
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
                PlaySound(menuConfirm);
                sceneManager.SetCurrentState(SceneState::Menu);
            }
            else if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
            {
                PlaySound(menuConfirm);
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

void Unload()
{
	// -- AUDIO --
	UnloadFont(font);
	UnloadMusicStream(music);

	UnloadSound(menuConfirm);
	UnloadSound(menuPause);
	UnloadSound(ballWallHitSound);
	UnloadSound(ballPaddleHitSound);
	UnloadSound(ballGoalSound);

	// -- TEXTURES --
	UnloadTexture(leftPaddeTexture);
	UnloadTexture(rightPaddleTexture);
    UnloadTexture(ballTexture);

}

//----------------------------------------------------------------------------------
// Game-Specific Functions Definition
//----------------------------------------------------------------------------------

void ScoreGoal(bool scoredByLeft)
{
    if (scoredByLeft)
    {
        leftScore++;

		ball.PlayGoalSound(scoredByLeft);

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

		ball.PlayGoalSound(scoredByLeft);

        // Reset ball
        ball.SetPosition(Vector2{ Consts::Window::WIDTH / 2.0f + Consts::Ball::X_OFFSET, Consts::Window::HEIGHT / 2.0f });
        ball.SetDirectionAngleRad(3 * PI / 4.0f);

        if (rightScore >= Consts::Score::WINNING_SCORE)
        {
            sceneManager.SetCurrentState(SceneState::Score);
        }
    }
}
