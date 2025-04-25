#ifndef POSITION_H
#define POSITION_H


class Position {
    int row;
    int col;

public:
    Position(int row, int col);

    int getRow() const;

    int getCol() const;
};


#endif //POSITION_H
