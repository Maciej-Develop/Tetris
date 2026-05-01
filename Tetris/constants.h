#ifndef TETRIS_CONSTANTS_H
#define TETRIS_CONSTANTS_H

#include "raylib.h"

namespace constant {

    // window's size
    inline constexpr int WIDTH = 300;
    inline constexpr int HEIGHT = 600;

    // board's size
    inline constexpr int ROWS = 20;
    inline constexpr int COLUMNS = 10;

    // Colors
    inline constexpr Color DARK_BLUE = {44,44,127,255};
}

#endif //TETRIS_CONSTANTS_H