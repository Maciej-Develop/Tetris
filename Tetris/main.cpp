#include "raylib.h"
#include "model/Game.h"
#include "model/Grid.h"
#include "model/blocks/IBlock.h"
#include "model/blocks/ZBlock.h"

int main() {
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Color myColor = {44, 44, 127, 255};

    Game game;

    while (!WindowShouldClose()) {
        game.handleInput();
        BeginDrawing();
        ClearBackground(myColor);
        game.draw();
        EndDrawing();
    }

    CloseWindow();
}
