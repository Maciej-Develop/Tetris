#include "Game.h"

#include <random>

#include "blocks/IBlock.h"
#include "blocks/JBlock.h"
#include "blocks/LBlock.h"
#include "blocks/OBlock.h"
#include "blocks/SBlock.h"
#include "blocks/TBlock.h"
#include "blocks/ZBlock.h"

Game::Game() {
    grid = Grid();
    blocks = {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
    currentBlock = getBlock();
    nextBlock = getBlock();
}

Block Game::getBlock() {
    if (blocks.empty()) {
        blocks = {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
    }
    int r = rand() % blocks.size();
    Block block = blocks[r];
    blocks.erase(blocks.begin() + r);
    return block;
}

void Game::draw() {
    grid.draw();
    currentBlock.draw();
}