#include "Game.h"

#include <random>

#include "Blocks/IBlock.h"
#include "Blocks/JBlock.h"
#include "Blocks/LBlock.h"
#include "Blocks/OBlock.h"
#include "Blocks/SBlock.h"
#include "Blocks/TBlock.h"
#include "Blocks/ZBlock.h"

Game::Game() : grid(Grid()),
               blocks(getAllBlocks()),
               currentBlock(getRandomBlock()),
               nextBlock(getRandomBlock()) {
}

std::vector<Block> Game::getAllBlocks() {
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
};

Block Game::getRandomBlock() {
    if (this->blocks.empty()) {
        this->blocks = getAllBlocks();
    }
    int i = rand() % this->blocks.size();
    Block b = this->blocks[i];
    blocks.erase(blocks.begin() + i);
    return b;
}

void Game::draw() const {
    this->grid.draw();
    this->currentBlock.draw();
}
