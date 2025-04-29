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
    InitWindow(500, 620, "Tetris");
    SetTargetFPS(60);

    Color myColor = {44, 44, 127, 255};
    Color lightMyColor = {59,85,162,255};
    Font font = LoadFontEx("resources/alpha_beta.png",64,0,0);

    Game game;

    while (!WindowShouldClose()) {
        game.handleInput();
        if (dropBlock(0.03)) {
            game.moveBlockDown();
        }
        BeginDrawing();
        ClearBackground(myColor);
        if (!game.isGameOver()) {
            DrawTextEx(font,"Score", {350,15},40,2, WHITE);
            DrawTextEx(font,"Next",{365,175},40,2, WHITE);
            DrawRectangleRounded({320,55,170,60},0.3,6,lightMyColor);
            DrawRectangleRounded({320,215,170,180},0.3,6,lightMyColor);
            game.draw();
        } else {
            DrawTextEx(font,"Game Over", {150,50},40,2, WHITE);
            DrawTextEx(font,"Press any key to restart", {70,100},30,2, WHITE);
        }
        EndDrawing();
    }

    CloseWindow();
}
