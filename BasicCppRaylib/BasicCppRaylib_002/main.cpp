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
// Variables Declaration
//----------------------------------------------------------------------------------

const int screenWidth = 800;
const int screenHeight = 450;
const char* windowName = "Basic C++ with Raylib";

Font font = { 0 };

Ball ball = { 0 };

vector<Vector2> hitPositions;

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