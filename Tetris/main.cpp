#include <iostream>
#include <ostream>
#include <raylib.h>
#include "constants.h"
#include "model/Grid.h"
#include "model/Blocks/IBlock.h"
#include "model/Blocks/LBlock.h"

int main() {
    InitWindow(constant::WIDTH, constant::HEIGHT, "My Tetris");
    SetTargetFPS(60);

    Grid g;
    IBlock l;

    // Game Loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(constant::m_DARK_BLUE);
        g.draw();
        l.draw();
        EndDrawing();
    }

    CloseWindow();
}
