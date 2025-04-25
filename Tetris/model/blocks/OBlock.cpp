#include "OBlock.h"

OBlock::OBlock() {
    this->color = 4;
    cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
    cells[1] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
    cells[2] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
    cells[3] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
    move(0,4);
}
