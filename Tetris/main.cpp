#include <raylib.h>
#include "constants.h"

int main() {

    InitWindow(constant::WIDTH, constant::HEIGHT, "My Tetris");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(constant::DARK_BLUE);
        EndDrawing();
    }

    CloseWindow();
}
