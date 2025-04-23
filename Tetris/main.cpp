#include "raylib.h"

int main() {

    InitWindow(300,600, "Tetris");
    SetTargetFPS(60);

    Color myColor = {44,44,127,255};

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(myColor);

        EndDrawing();
    }

    CloseWindow();
}