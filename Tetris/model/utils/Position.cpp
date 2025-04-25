#include "Position.h"

Position::Position(int row, int col) {
    this->row = row;
    this->col = col;
}

int Position::getRow() const {
    return this->row;
}

int Position::getCol() const {
    return this->col;
}

