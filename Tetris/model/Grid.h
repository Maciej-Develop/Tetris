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

    bool isRowFull(int row);

    void clearRow(int row);

    void moveRow(int row, int numRows);

public:
    Grid();

    bool isInside(int row, int col);

    bool isEmpty(int row, int col) const;

    void setGridCell(Position p, int color);

    int clearFullRows();

    // to remove
    void print();

    void draw();
};


#endif
