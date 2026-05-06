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
    return this->grid.at(row).at(column);
}

void Grid::setCell(const int row, const int column, int value) {
    if (!isCellInside(row, column)) {
        throw std::out_of_range("out of range");
    }
    this->grid.at(row).at(column) = value;
}

bool Grid::isCellInside(int row, int column) const {
    return row >= 0 && row < constant::ROWS && column >= 0 && column < constant::COLUMNS;
}

bool Grid::isCellEmpty(int row, int column) const {
    return this->grid.at(row).at(column) == 0;
}

bool Grid::isRowFull(int row) const {
    for (int column = 0; column < constant::COLUMNS; column++) {
        if (this->grid.at(row).at(column) == 0) {
            return false;
        }
    }
    return true;
}

void Grid::clearRow(int row) {
    for (int column = 0; column < constant::COLUMNS; column++) {
        this->grid.at(row).at(column) = 0;
    }
}

void Grid::moveRowDown(int row, int numRow) {
    for (int column = 0; column < constant::COLUMNS; column++) {
        this->grid.at(row + numRow).at(column) = this->grid.at(row).at(column);
        this->grid.at(row).at(column) = 0;
    }
}

void Grid::clearFullRows() {
    int fullRows = 0;
    for (int row = constant::ROWS - 1; row >= 0; row--) {
        if (isRowFull(row)) {
            clearRow(row);
            fullRows++;
        } else if (fullRows > 0) {
            moveRowDown(row, fullRows);
        }
    }
}

void Grid::reset() {
    for (int row = 0; row < constant::ROWS; row++) {
        for (int column = 0; column < constant::COLUMNS; column++) {
            this->grid.at(row).at(column) = 0;
        }
    }
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
    for (int row = 0; row < constant::ROWS; row++) {
        for (int column = 0; column < constant::COLUMNS; column++) {
            int cellValue = this->getCell(row, column);
            DrawRectangle(column * constant::CELL_SIZE + 11,
                          row * constant::CELL_SIZE + 11,
                          constant::CELL_SIZE - 1,
                          constant::CELL_SIZE - 1,
                          colors.at(cellValue));
        }
    }
}
