#include <iostream>
#include <raylib.h>
#include "constants.h"
#include "model/Game.h"


int main() {
    InitWindow(constant::WIDTH, constant::HEIGHT, "My Tetris");
    SetTargetFPS(60);

    Game g;

    // Game Loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(constant::m_DARK_BLUE);
        g.draw();
        g.handleInput();
        EndDrawing();
    }

    CloseWindow();
}
