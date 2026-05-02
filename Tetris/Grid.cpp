#include "Grid.h"

#include <algorithm>
#include <iostream>

Grid::Grid() {
    initialize();
}

void Grid::initialize() {
    for (auto &row : grid) {
        std::ranges::fill(row, 0);
    }
}

const int &Grid::getCell(const int row, const int column) const {
    return this->grid[row][column];
}

void Grid::setCell(const int row, const int column, int value) {
    this->grid[row][column] = value;
}

// @TODO delete
void Grid::print() const {
    std::ranges::for_each(grid.begin(), grid.end(),[](auto & row) {
        std::ranges::for_each(row.begin(), row.end(),[](auto & col) {
            std::cout << col << " ";
        });
        std::cout << '\n';
    });
}
