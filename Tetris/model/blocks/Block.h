#ifndef BLOCK_H
#define BLOCK_H
#include <map>
#include <vector>

#include "../utils/Position.h"


class Block {

    int id;
    int cellsize;
    int rotattionState;
    std::pmr::map<int, std::vector<Position>> cells;

public:

    Block();

    int getId() const;
};


#endif //BLOCK_H
