#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H
#include "Grid.h"
#include "Blocks/Block.h"


class Game {
private:
    Grid grid;
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;

    std::vector<Block> getAllBlocks();

public:
    Game();

    Block getRandomBlock();

    void handleInput();

    bool isBlockInside();

    void rotateBlock();

    // @TODO delete
    void draw() const;
};


#endif //TETRIS_GAME_H
