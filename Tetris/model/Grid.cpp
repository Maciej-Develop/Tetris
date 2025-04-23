#include "Grid.h"

#include <algorithm>
#include <iostream>

Grid::Grid() {
    rows = 20;
    cols = 10;
    cellSize = 30;
    grid = std::vector(rows, std::vector(cols, 0));
}

//to remove
void Grid::print() {
    std::ranges::for_each(grid, [](const std::vector<int>& row) {
        std::ranges::for_each(row, [](const int& box) {
            std::cout << box << " ";
        });
        std::cout << std::endl;
    });
}


