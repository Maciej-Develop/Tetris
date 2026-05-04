#ifndef TETRIS_GRID_H
#define TETRIS_GRID_H

#include <array>
#include <vector>
#include "raylib.h"
#include "../constants.h"


class Grid {
private:
    std::array<std::array<int, constant::COLUMNS>, constant::ROWS> grid;
    std::vector<Color> colors;

public:
    Grid();

    [[nodiscard]] const int &getCell(int, int) const;

    void setCell(int, int, int);

    [[nodiscard]] bool isCellInside(int, int) const;

    [[nodiscard]] bool isCellEmpty(int, int) const;

    // @TODO delete
    void print() const;

    // @TODO delete
    void draw() const;
};


#endif //TETRIS_GRID_H
