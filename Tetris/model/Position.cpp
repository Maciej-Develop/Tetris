#include "Position.h"

Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
}

const int& Position::getX() const {
    return x;
}

const int& Position::getY() const {
    return y;
}
