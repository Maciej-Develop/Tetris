#include "Game.h"

#include <random>
#include <algorithm>

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
    gameOver = false;
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

void Game::restart() {
    grid.restart();
    blocks = {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
    currentBlock = getBlock();
    nextBlock = getBlock();
}

void Game::handleInput() {
    int key = GetKeyPressed();
    if (gameOver && key != 0) {
        gameOver = false;
        restart();
    }
    switch (key) {
        case KEY_W: moveBlockUp();
            break;
        case KEY_S: moveBlockDown();
            break;
        case KEY_D: moveBlockRight();
            break;
        case KEY_A: moveBlockLeft();
            break;
        case KEY_Q: rotateBlockClock();
            break;
        case KEY_E: rotateBlockCounterClock();
            break;
        default:
            break;
    }
}

void Game::moveBlockUp() {
    if (!gameOver) {
        currentBlock.move(-1, 0);
        if (!isBlockInside()) {
            currentBlock.move(1, 0);
        }
    }
}

void Game::moveBlockDown() {
    if (!gameOver) {
        currentBlock.move(1, 0);
        if (!isBlockInside() || isBlockTouched()) {
            currentBlock.move(-1, 0);
            lockBlock();
        }
    }
}

void Game::moveBlockLeft() {
    if (!gameOver) {
        currentBlock.move(0, -1);
        if (!isBlockInside() || isBlockTouched()) {
            currentBlock.move(0, 1);
        }
    }
}

void Game::moveBlockRight() {
    if (!gameOver) {
        currentBlock.move(0, 1);
        if (!isBlockInside() || isBlockTouched()) {
            currentBlock.move(0, -1);
        }
    }
}

bool Game::isBlockInside() {
    std::vector<Position> positions = currentBlock.getPositions();
    for (Position p: positions) {
        if (!grid.isInside(p.getRow(), p.getCol())) {
            return false;
        }
    }
    return true;
}

bool Game::isBlockTouched() {
    for (auto& p: currentBlock.getPositions()) {
        if (!grid.isEmpty(p.getRow(), p.getCol())) {
            return true;
        }
    }
    return false;
}

void Game::rotateBlockClock() {
    currentBlock.rotateClock();
    if (!isBlockInside() || isBlockTouched()) {
        currentBlock.rotateCounterClock();
    }
}

void Game::rotateBlockCounterClock() {
    currentBlock.rotateCounterClock();
    if (!isBlockInside() || isBlockTouched()) {
        currentBlock.rotateClock();
    }
}

void Game::lockBlock() {
    std::vector<Position> positions = currentBlock.getPositions();
    std::ranges::for_each(positions, [&](Position p) {
        grid.setGridCell(p,currentBlock.getColor());
    });
    currentBlock = nextBlock;
    if (isBlockTouched()) {
        gameOver = true;
    }
    nextBlock = getBlock();
    grid.clearFullRows();
}