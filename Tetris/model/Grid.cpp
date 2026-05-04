#include "Grid.h"
#include <algorithm>
#include <iostream>

Grid::Grid() : grid{},
               colors{
                   constant::m_DARK_GRAY,
                   constant::m_GREEN,
                   constant::m_RED,
                   constant::m_ORANGE,
                   constant::m_YELLOW,
                   constant::m_PURPLE,
                   constant::m_CYAN,
                   constant::m_BLUE
               } {
}

const int &Grid::getCell(const int row, const int column) const {
    return this->grid[row][column];
}

void Grid::setCell(const int row, const int column, int value) {
    if (!isCellInside(row,column)) {
        throw std::out_of_range("out of range");
    }
    this->grid[row][column] = value;
}

bool Grid::isCellInside(int row, int column) const {
    return row >= 0 && row < constant::ROWS && column >= 0 && column < constant::COLUMNS;
}

bool Grid::isCellEmpty(int row, int column) const {
    return this->grid[row][column] == 0;
}

void Grid::print() const {
    std::ranges::for_each(grid.begin(), grid.end(), [](auto &row) {
        std::ranges::for_each(row.begin(), row.end(), [](auto &col) {
            std::cout << col << " ";
        });
        std::cout << '\n';
    });
}

void Grid::draw() const {
    for (int row = 0; row < this->grid.size(); row++) {
        for (int column = 0; column < this->grid[0].size(); column++) {
            int cellValue = this->getCell(row, column);
            DrawRectangle(column * constant::CELL_SIZE + 1,
                          row * constant::CELL_SIZE + 1,
                          constant::CELL_SIZE - 1,
                          constant::CELL_SIZE - 1,
                          colors.at(cellValue));
        }
    }
}
