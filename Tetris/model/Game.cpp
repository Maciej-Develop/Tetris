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

void Game::handleInput() {
    int key = GetKeyPressed();
    switch (key) {
        case KEY_UP: moveBlockUp();
            break;
        case KEY_DOWN: moveBlockDown();
            break;
        case KEY_RIGHT: moveBlockRight();
            break;
        case KEY_LEFT: moveBlockLeft();
            break;
        default:
            break;
    }
}

void Game::moveBlockUp() {
    currentBlock.move(-1, 0);
    if (!isBlockInside()) {
        moveBlockDown();
    }
}

void Game::moveBlockDown() {
    currentBlock.move(1, 0);
    if (!isBlockInside()) {
        moveBlockUp();
    }
}

void Game::moveBlockLeft() {
    currentBlock.move(0, -1);
    if (!isBlockInside()) {
        moveBlockRight();
    }
}

void Game::moveBlockRight() {
    currentBlock.move(0, 1);
    if (!isBlockInside()) {
        moveBlockLeft();
    }
}

bool Game::isBlockInside() {
    std::vector<Position> positions = currentBlock.getPositions();
    for (Position p : positions) {
        if (!grid.isInside(p.getRow(),p.getCol())) {
            return false;
        }
    }
    return true;
}
