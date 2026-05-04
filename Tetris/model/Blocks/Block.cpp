#include "Block.h"

#include <algorithm>
#include <utility>

#include "../../constants.h"

Block::Block(int id, std::vector<std::vector<Position> > cells) : id{id},
                                                                    rotation{0},
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

void Block::draw() const {
    auto& currentCell = this->cells.at(rotation);
    std::ranges::for_each(currentCell, [&](auto &c) {
        DrawRectangle(c.getY() * constant::CELL_SIZE + 1,
                      c.getX() * constant::CELL_SIZE + 1,
                      constant::CELL_SIZE - 1,
                      constant::CELL_SIZE - 1,
                      colors.at(id));
    });
}
