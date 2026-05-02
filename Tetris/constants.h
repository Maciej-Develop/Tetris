#ifndef TETRIS_CONSTANTS_H
#define TETRIS_CONSTANTS_H

#include "raylib.h"

namespace constant {
    // window's size
    inline constexpr int WIDTH = 300;
    inline constexpr int HEIGHT = 600;

    inline constexpr int CELL_SIZE = 30;

    // board's size
    inline constexpr int ROWS = 20;
    inline constexpr int COLUMNS = 10;

    // Colors
    inline constexpr Color m_DARK_BLUE = {44, 44, 127, 255};

    inline constexpr Color m_DARK_GRAY = {26, 31, 40, 255};
    inline constexpr Color m_GREEN = {47, 230, 23, 255};
    inline constexpr Color m_RED = {232, 18, 18, 255};
    inline constexpr Color m_ORANGE = {226, 116, 17, 255};
    inline constexpr Color m_YELLOW = {237, 234, 4, 255};
    inline constexpr Color m_PURPLE = {166, 0, 247, 255};
    inline constexpr Color m_CYAN = {21, 204, 209, 255};
    inline constexpr Color m_BLUE = {13, 64, 216, 255};
}

#endif //TETRIS_CONSTANTS_H
