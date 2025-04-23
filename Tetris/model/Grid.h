#ifndef GRID_H
#define GRID_H
#include <array>
#include <vector>


class Grid {

    int rows;
    int cols;
    int cellSize;
    std::vector<std::vector<int>> grid;

public:

    Grid();

// to remove
    void print();
};


#endif
