#include <iostream>
#include <ostream>
#include <raylib.h>
#include "constants.h"
#include "Grid.h"

int main() {
    InitWindow(constant::WIDTH, constant::HEIGHT, "My Tetris");
    SetTargetFPS(60);

    Grid g;
    g.setCell(1, 2, 2);
    g.setCell(2, 1, 4);
    g.setCell(0, 0, 5);

    // Game Loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(constant::m_DARK_BLUE);
        g.draw();
        EndDrawing();
    }

    CloseWindow();
}
