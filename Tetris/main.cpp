#include <iostream>
#include <raylib.h>
#include "constants.h"
#include "model/Game.h"

bool eventTrigger(double interval) {
    static double lastUpdateTime = 0;
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
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

        if (eventTrigger(0.5)) {
            g.gravity();
        }

        DrawText("Score", 380, 15, 38, WHITE);
        DrawText("Next", 390, 175, 38, WHITE);
        if (g.getIsGameOver()) {
            DrawText("GAME OVER", 318, 450, 38, WHITE);
        }
        DrawRectangleRounded({350,55, 170, 60},0.3,6, constant::m_LIGHT_BLUE);
        DrawRectangleRounded({350,215, 170, 180},0.3,6, constant::m_LIGHT_BLUE);

        EndDrawing();
    }

    CloseWindow();
}
