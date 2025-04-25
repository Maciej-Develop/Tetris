#include "Block.h"

#include <algorithm>

Block::Block() {
    cellSize = 30;
    rotationState = 0;
    rowOffset = 0;
    colOffset = 0;
    colors = getColors();
}

void Block::draw() {
    const std::vector<Position> &block = getPositions();
    for (auto p: block) {
        DrawRectangle(p.getCol() * cellSize + 1, p.getRow() * cellSize + 1, cellSize - 1, cellSize - 1, colors[color]);
    }
}

void Block::move(int rows, int cols) {
    this->rowOffset += rows;
    this->colOffset += cols;
}

std::vector<Position> Block::getPositions() {
    std::vector<Position> positions;
    std::ranges::for_each(cells[rotationState], [&](const Position &p) {
        const Position newPosition(p.getRow() + rowOffset, p.getCol() + colOffset);
        positions.push_back(newPosition);
    });
    return positions;
}
