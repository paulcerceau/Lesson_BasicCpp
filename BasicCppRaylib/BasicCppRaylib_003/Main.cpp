#include "raylib.h"

#include <iostream>
#include <vector>

using std::vector;

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------

typedef struct Ball {
    Vector2 position;
    Vector2 speed;
    int radius;
    Color color;
} Ball;

//----------------------------------------------------------------------------------
// Global Variables Declaration
//----------------------------------------------------------------------------------

static const int screenWidth = 800;
static const int screenHeight = 450;
static const char* windowName = "Basic C++ with Raylib";

static Font font = { 0 };

static bool gameOver = false;
static bool pause = false;

static Ball ball = { 0 };

static vector<Vector2> hitPositions;

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------

static void InitGame();
static void Update();
static void UpdateDrawFrame();
static void Draw();
static void DrawUI();

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------

int main() {
    //v Initialization ===============================================
    InitWindow(screenWidth, screenHeight, windowName);

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
// Module Functions Definition
//----------------------------------------------------------------------------------

void InitGame()
{
    // -- FONT --
    font = LoadFont("../resources/fonts/alagard.png");

    // -- BALL --
    ball.position = Vector2{ 50.0f, 50.0f };
    ball.speed = Vector2{ 4.0f, 4.0f };
    ball.radius = 20;
    ball.color = DARKBLUE;

    hitPositions.clear();

}

void UpdateDrawFrame()
{
    //v Update =======================================================
    Update();

    //^ Update =======================================================
    //v Draw =========================================================
    BeginDrawing();
    ClearBackground(SKYBLUE);

    Draw();
    DrawUI();

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
            // -- BALL --
            // Move the ball
            ball.position.x += ball.speed.x;
            ball.position.y += ball.speed.y;

            // Bounce the ball
            if ((ball.position.x >= (screenWidth - ball.radius)) || (ball.position.x <= ball.radius))
            {
                ball.speed.x *= -1;

                hitPositions.push_back(ball.position);
            }
            if ((ball.position.y >= (screenHeight - ball.radius)) || (ball.position.y <= ball.radius))
            {
                ball.speed.y *= -1;

                hitPositions.push_back(ball.position);
            }
        }
    }
}

void Draw()
{
    DrawCircle(ball.position.x, ball.position.y, ball.radius, ball.color);
}

void DrawUI()
{
    for (int i = 0; i < hitPositions.size(); i++)
    {
        DrawTextEx(font, "Boing", hitPositions[i], 20, 3, RED);
    }
}