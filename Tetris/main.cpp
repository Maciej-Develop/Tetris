#include <iostream>
#include <ostream>
#include <raylib.h>
#include "constants.h"
#include "Grid.h"

int main() {

    InitWindow(constant::WIDTH, constant::HEIGHT, "My Tetris");
    SetTargetFPS(60);

    // Game Loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(constant::DARK_BLUE);
        EndDrawing();
    }

    CloseWindow();
}
