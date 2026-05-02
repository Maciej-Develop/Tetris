#ifndef TETRIS_BLOCK_H
#define TETRIS_BLOCK_H


class Block {
private:
    int id;

public:
    Block();

    [[nodiscard]] const int &getId() const;
};


#endif //TETRIS_BLOCK_H
