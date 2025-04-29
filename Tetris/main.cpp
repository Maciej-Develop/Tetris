#include "raylib.h"
#include "GLFW/glfw3.h"
#include "model/Game.h"
#include "model/Grid.h"
#include "model/blocks/IBlock.h"
#include "model/blocks/ZBlock.h"

double lastUpdateTime = 0;

bool dropBlock(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main() {
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Color myColor = {44, 44, 127, 255};

    Game game;

    while (!WindowShouldClose()) {
        game.handleInput();
        if (dropBlock(0.3)) {
            game.moveBlockDown();
        }
        BeginDrawing();
        ClearBackground(myColor);
        game.draw();
        EndDrawing();
    }

    CloseWindow();
}
