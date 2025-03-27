#include "raylib.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello World" << endl;

    InitWindow(300, 300, "My first Raylib window!");
    SetTargetFPS(60);

    // Init

    while (!WindowShouldClose()) {
        // Update

        BeginDrawing();
        ClearBackground(DARKGREEN);

        // Draw

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
