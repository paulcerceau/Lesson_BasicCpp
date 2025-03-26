#include "raylib.h"
#include "Ball.h"

#include <iostream>
#include <vector>

using std::vector;

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------



//----------------------------------------------------------------------------------
// Variables Declaration
//----------------------------------------------------------------------------------

const int screenWidth = 800;
const int screenHeight = 450;
const char* windowName = "Basic C++ with Raylib";

Font font = { 0 };

bool gameOver = false;
bool pause = false;

Ball ball;

//----------------------------------------------------------------------------------
// Functions Declaration
//----------------------------------------------------------------------------------

void InitGame();
void Update();
void UpdateDrawFrame();
void Draw();
void DrawUI();

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
// Functions Definition
//----------------------------------------------------------------------------------

void InitGame()
{
    // -- FONT --
    font = LoadFont("../resources/fonts/alagard.png");

    // -- BALL --
    Vector2 startPosition{ 100.0f, 100.0f };
    Vector2 speed{ 2.0f, 2.0f };

    ball.Init(startPosition, speed, 10.0f, DARKPURPLE);

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

        }
    }
}

void Draw()
{
    ball.Draw();
}

void DrawUI()
{

}