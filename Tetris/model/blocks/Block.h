#ifndef BLOCK_H
#define BLOCK_H
#include <map>
#include <vector>

#include "../utils/Colors.h"
#include "../utils/Position.h"


class Block {
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int colOffset;

protected:
    int color;
    std::pmr::map<int, std::vector<Position> > cells;

public:
    Block();

    const int& getColor() const;

    void draw();

    void move(int x, int y);

    std::vector<Position> getPositions();

    void rotateClock();

    void rotateCounterClock();
};


#endif //BLOCK_H
