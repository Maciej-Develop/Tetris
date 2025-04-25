#include "Block.h"

Block::Block() {
    cellsize = 30;
    rotattionState = 0;
    colors = getColors();
}

void Block::draw() {
    const std::vector<Position> &block = cells[rotattionState];
    for (auto p : block) {
        DrawRectangle(p.getCol() * cellsize + 1, p.getRow() * cellsize + 1, cellsize - 1, cellsize - 1, colors[color]);
    }
}
