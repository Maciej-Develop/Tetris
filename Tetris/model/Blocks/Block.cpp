#include "Block.h"

#include <algorithm>
#include <utility>

#include "../../constants.h"

Block::Block(int id, std::vector<std::vector<Position> > cells) : id{id},
                                                                  rotation{0},
                                                                  rowOffset{0},
                                                                  columnOffset{0},
                                                                  cells{std::move(cells)},
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

const int &Block::getId() const {
    return this->id;
}

void Block::moveBlock(int x_movement, int y_movement) {
    this->rowOffset += x_movement;
    this->columnOffset += y_movement;
}

std::vector<Position> Block::getCurrentCells() const {
    std::vector<Position> cells = this->cells[this->rotation];
    std::vector<Position> currentCells;
    std::ranges::for_each(cells.begin(), cells.end(), [&](auto &cell) {
        Position currentCell{cell.getX() + this->rowOffset, cell.getY() + this->columnOffset};
        currentCells.push_back(currentCell);
    });
    return currentCells;
}

void Block::rotate() {
    this->rotation++;
    if (this->rotation == this->cells.size()) {
        this->rotation = 0;
    }
}

void Block::unrotate() {
    this->rotation--;
    if (this->rotation < 0) {
        this->rotation = this->cells.size() - 1;
    }
}


void Block::draw() const {
    auto currentCell = getCurrentCells();
    std::ranges::for_each(currentCell, [&](auto &c) {
        DrawRectangle(c.getY() * constant::CELL_SIZE + 11,
                      c.getX() * constant::CELL_SIZE + 11,
                      constant::CELL_SIZE - 1,
                      constant::CELL_SIZE - 1,
                      colors.at(id));
    });
}
