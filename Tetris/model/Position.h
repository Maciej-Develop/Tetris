#ifndef TETRIS_POSITION_H
#define TETRIS_POSITION_H


class Position {
private:
    int x;
    int y;

public:
    Position(int x, int y);

    [[nodiscard]] const int &getX() const;

    [[nodiscard]] const int &getY() const;
};


#endif //TETRIS_POSITION_H
