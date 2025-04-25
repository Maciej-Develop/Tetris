#include "Grid.h"

#include <algorithm>
#include <iostream>

Grid::Grid() {
    rows = 20;
    cols = 10;
    cellSize = 30;
    grid = std::vector(rows, std::vector(cols, 0));
    colors = getColors();
}

//to remove
void Grid::print() {
    std::ranges::for_each(grid, [](const std::vector<int> &row) {
        std::ranges::for_each(row, [](const int &box) {
            std::cout << box << " ";
        });
        std::cout << std::endl;
    });
}

std::vector<Color> Grid::getColors() {
    Color darkGrey = {26, 31, 40, 255};
    Color green = {47, 230, 23, 255};
    Color red = {232, 18, 18, 255};
    Color orange = {226, 116, 17, 255};
    Color yellow = {237, 234, 4, 255};
    Color purple = {166, 0, 247, 255};
    Color cyan = {21, 204, 209, 255};
    Color blue = {13, 64, 216, 255};

    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}

void Grid::draw() {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int value = grid[row][col];
            DrawRectangle(col * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[value]);
        }
    }
}
