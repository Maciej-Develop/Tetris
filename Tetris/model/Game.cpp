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
               nextBlock(getRandomBlock()),
               isGameOver(false),
               score(0) {
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

bool Game::getIsGameOver() const {
    return this->isGameOver;
}

int Game::getScore() const {
    return this->score;
}

void Game::handleInput() {
    int keyPressed = GetKeyPressed();
    if (this->isGameOver && keyPressed != 0) {
        this->isGameOver = false;
        reset();
    }
    switch (keyPressed) {
        case KEY_DOWN:
            if (!this->isGameOver) {
                this->currentBlock.moveBlock(1, 0);
                if (!isBlockInside() || !isBlockClear()) {
                    this->currentBlock.moveBlock(-1, 0);
                    lockBlock();
                }
                updateScore(0, 1);
            }
            break;
        case KEY_LEFT:
            if (!this->isGameOver) {
                this->currentBlock.moveBlock(0, -1);
                if (!isBlockInside() || !isBlockClear()) {
                    this->currentBlock.moveBlock(0, 1);
                }
            }
            break;
        case KEY_RIGHT:
            if (!this->isGameOver) {
                this->currentBlock.moveBlock(0, 1);
                if (!isBlockInside() || !isBlockClear()) {
                    this->currentBlock.moveBlock(0, -1);
                }
            }
            break;
        case KEY_UP:
            if (!this->isGameOver) {
                this->rotateBlock();
            }
        default:
            break;
    }
}

void Game::gravity() {
    if (!this->isGameOver) {
        this->currentBlock.moveBlock(1, 0);
        if (!isBlockInside() || !isBlockClear()) {
            this->currentBlock.moveBlock(-1, 0);
            lockBlock();
        }
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
    std::cout << "lock" << '\n';
    std::vector<Position> block = this->currentBlock.getCurrentCells();
    for (auto &cell: block) {
        grid.setCell(cell.getX(), cell.getY(), currentBlock.getId());
    }
    this->currentBlock = this->nextBlock;
    if (!isBlockClear()) {
        this->isGameOver = true;
    }
    this->nextBlock = getRandomBlock();
    int clears = this->grid.clearFullRows();
    updateScore(clears, 0);
}

void Game::updateScore(int linesCleared, int moveDownPoints) {
    if (linesCleared == 1) {
        score += 100;
    } else if (linesCleared > 1) {
        score += 100 + 200 * (linesCleared - 1);
    }

    score += moveDownPoints;
}

void Game::reset() {
    grid.reset();
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    score = 0;
}

void Game::draw() const {
    this->grid.draw();
    this->currentBlock.draw(11, 11);
    this->nextBlock.draw(295, 270);
}
