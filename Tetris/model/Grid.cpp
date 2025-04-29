#include "Grid.h"

#include <algorithm>
#include <iostream>

#include "utils/Colors.h"

Grid::Grid() {
    rows = 20;
    cols = 10;
    cellSize = 30;
    grid = std::vector(rows, std::vector(cols, 0));
    colors = getColors();
}

bool Grid::isInside(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        return false;
    }
    return true;
}

void Grid::setGridCell(Position p, int color) {
    grid[p.getRow()][p.getCol()] = color;
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

void Grid::draw() {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int value = grid[row][col];
            DrawRectangle(col * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[value]);
        }
    }
}
