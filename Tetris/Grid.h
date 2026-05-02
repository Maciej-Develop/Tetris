#ifndef TETRIS_GRID_H
#define TETRIS_GRID_H
#include <array>

#include "constants.h"


class Grid {

    private:
        std::array<std::array<int, constant::COLUMNS>,constant::ROWS> grid{};
        void initialize();

    public:
        Grid();
        void print() const;
        [[nodiscard]] const int& getCell(int,int) const;
        void setCell(int,int,int);
};


#endif //TETRIS_GRID_H