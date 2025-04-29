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

void Grid::restart() {
    grid = std::vector(rows, std::vector(cols, 0));
}

bool Grid::isInside(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        return false;
    }
    return true;
}

bool Grid::isEmpty(int row, int col) const {
    if (grid[row][col] == 0) {
        return true;
    }
    return false;
}

void Grid::setGridCell(Position p, int color) {
    grid[p.getRow()][p.getCol()] = color;
}

int Grid::clearFullRows() {
    int completed = 0;
    for (int row = rows - 1; row >= 0; row--) {
        if (isRowFull(row)) {
            clearRow(row);
            completed++;
        } else if (completed > 0) {
            moveRow(row,completed);
        }
    }
    return completed;
}

bool Grid::isRowFull(int row) {
    for (int col = 0; col < cols; col++) {
        if (grid[row][col] == 0) {
            return false;
        }
    }
    return true;
}

void Grid::clearRow(int row) {
    std::ranges::fill(grid[row], 0);
}

void Grid::moveRow(int row, int numRows) {
    std::ranges::copy(grid[row], grid[row+numRows].begin());
    std::ranges::fill(grid[row], 0);
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
            DrawRectangle(col * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[value]);
        }
    }
}
