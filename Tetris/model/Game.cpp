#include "Game.h"

#include <algorithm>
#include <iostream>
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

void Game::handleInput() {
    int keyPressed = GetKeyPressed();
    switch (keyPressed) {
        case KEY_DOWN:
            this->currentBlock.moveBlock(1, 0);
            if (!isBlockInside() || !isBlockClear()) {
                this->currentBlock.moveBlock(-1, 0);
                lockBlock();
            }
            break;
        case KEY_LEFT:
            this->currentBlock.moveBlock(0, -1);
            if (!isBlockInside() || !isBlockClear()) {
                this->currentBlock.moveBlock(0, 1);
            }
            break;
        case KEY_RIGHT:
            this->currentBlock.moveBlock(0, 1);
            if (!isBlockInside() || !isBlockClear()) {
                this->currentBlock.moveBlock(0, -1);
            }
            break;
        case KEY_UP:
            this->rotateBlock();
        default:
            break;
    }
}

void Game::gravity() {
    this->currentBlock.moveBlock(1, 0);
    if (!isBlockInside() || !isBlockClear()) {
        this->currentBlock.moveBlock(-1, 0);
        lockBlock();
    }
}

bool Game::isBlockInside() {
    std::vector<Position> block = this->currentBlock.getCurrentCells();
    return std::ranges::all_of(block.begin(), block.end(), [&](auto &cell) {
        return this->grid.isCellInside(cell.getX(), cell.getY());
    });
}

bool Game::isBlockClear() {
    std::vector<Position> block = this->currentBlock.getCurrentCells();
    return std::ranges::all_of(block.begin(), block.end(), [&](auto &cell) {
        return this->grid.isCellEmpty(cell.getX(), cell.getY());
    });
}

void Game::rotateBlock() {
    this->currentBlock.rotate();
    if (!isBlockInside()) {
        this->currentBlock.unrotate();
    }
}

void Game::lockBlock() {
    std::vector<Position> block = this->currentBlock.getCurrentCells();
    for (auto &cell : block) {
        grid.setCell(cell.getX(),cell.getY(), currentBlock.getId());
    }
    this->currentBlock = this->nextBlock;
    this->nextBlock = getRandomBlock();
}

void Game::draw() const {
    this->grid.draw();
    this->currentBlock.draw();
}
