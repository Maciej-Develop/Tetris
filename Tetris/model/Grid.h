#ifndef GRID_H
#define GRID_H
#include <array>
#include <vector>

#include "raylib.h"


class Grid {
    int rows;
    int cols;
    int cellSize;
    std::vector<std::vector<int> > grid;
    std::vector<Color> colors;

public:
    Grid();

    bool isInside(int row, int col);

    // to remove
    void print();

    void draw();
};


#endif
