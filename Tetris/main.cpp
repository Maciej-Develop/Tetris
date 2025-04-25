#include "raylib.h"
#include "model/Grid.h"
#include "model/blocks/ZBlock.h"

int main() {
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Color myColor = {44, 44, 127, 255};

    Grid grid;
    ZBlock block;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(myColor);
        grid.draw();
        block.draw();

        EndDrawing();
    }

    CloseWindow();
}
