#include <iostream>
#include <raylib.h>
#include "constants.h"
#include "model/Game.h"
#include "model/Blocks/LBlock.h"

bool eventTrigger(double interval) {
    static double lastUpdateTime = 0;
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval ) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

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

        if (eventTrigger(0.05)) {
            g.gravity();
        }
        EndDrawing();
    }

    CloseWindow();
}
