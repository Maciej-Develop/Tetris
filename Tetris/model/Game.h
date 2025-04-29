#ifndef GAME_H
#define GAME_H
#include "Grid.h"
#include "blocks/Block.h"


class Game {
    Grid grid;
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    bool gameOver;

public:
    Game();

    Block getBlock();

    void draw();

    void restart();

    void handleInput();

    void moveBlockUp();

    void moveBlockDown();

    void moveBlockLeft();

    void moveBlockRight();

    bool isBlockInside();

    bool isBlockTouched();

    void rotateBlockClock();

    void rotateBlockCounterClock();

    void lockBlock();
};


#endif //GAME_H
