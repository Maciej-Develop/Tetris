#ifndef GRID_H
#define GRID_H
#include <vector>

#include "raylib.h"
#include "utils/Position.h"


class Grid {
    int rows;
    int cols;
    int cellSize;
    std::vector<std::vector<int> > grid;
    std::vector<Color> colors;

public:
    Grid();

    bool isInside(int row, int col);

    void setGridCell(Position p, int color);

    // to remove
    void print();

    void draw();
};


#endif
