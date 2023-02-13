//
// Created by jibbe on 13-2-23.
//

#ifndef PROGRAMMING2_MAZE_HPP
#define PROGRAMMING2_MAZE_HPP

#include <array>
#include <iostream>

enum Direction{
    UP, RIGHT, DOWN, LEFT
};

struct Position{
    int x;
    int y;

    bool operator!=(Position pos){
        return this->x != pos.x || this->y != pos.y;
    }
};

class Maze {
    std::array<std::array<char, 12>, 12> map;
    Position startingPosition = {0, 0};
    Position currentPosition;
    Direction direction = UP;

    bool determineStart(Position pos);
public:
    Maze(std::array<std::array<char, 12>, 12> map);
    void render();
    Position getStartingPosition();
    bool traverse();
};


#endif //PROGRAMMING2_MAZE_HPP
