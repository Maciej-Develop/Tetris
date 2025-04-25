#ifndef GAME_H
#define GAME_H
#include "Grid.h"
#include "blocks/Block.h"


class Game {
    Grid grid;
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;

public:
    Game();

    Block getBlock();

    void draw();
};


#endif //GAME_H
