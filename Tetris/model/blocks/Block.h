#ifndef BLOCK_H
#define BLOCK_H
#include <map>
#include <vector>

#include "../utils/Colors.h"
#include "../utils/Position.h"


class Block {
    int cellsize;
    int rotattionState;
    std::vector<Color> colors;

protected:
    int color;
    std::pmr::map<int, std::vector<Position>> cells;

public:
    Block();

    void draw();
};


#endif //BLOCK_H
