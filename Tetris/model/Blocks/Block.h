#ifndef TETRIS_BLOCK_H
#define TETRIS_BLOCK_H
#include <array>
#include <vector>
#include "../Position.h"
#include "raylib.h"


class Block {

private:
    int id;
    int rotation;
    int rowOffset;
    int columnOffset;
    std::vector<std::vector<Position>> cells;
    std::vector<Color> colors;

public:
    Block(int, std::vector<std::vector<Position>>);

    [[nodiscard]] const int &getId() const;

    void moveBlock(int , int);

    std::vector<Position> getCurrentCells() const;

    void rotate();

    void unrotate();

    // @TODO delete
    void draw() const;
};


#endif //TETRIS_BLOCK_H
