//==============================================================
// Filename : maze.hpp
// Authors : Jibbe Andringa S2336219
// Group : 12
// License : N.A.
// Description : Implementation of the Maze class
//==============================================================

#include "maze.hpp"

Maze::Maze(std::array<std::array<char, 12>, 12> map) : map{map}{
    determineStart(startingPosition);
    currentPosition = startingPosition;
}

void Maze::render() {
    for(auto row : map){
        for(auto cell : row){
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
}

bool Maze::determineStart(Position position) {
    if(map[position.y][position.x] == 'x'){
        startingPosition = position;
        return true;
    }
    else if (position.x < map[position.x].size() - 1){
        position.x++;
        return determineStart(position);
    }
    else if(position.y < map.size() - 1){
        position.x = 0;
        position.y++;
        return determineStart(position);
    }
    else{
        std::cout << "ERROR: Starting position not found!" << std::endl;
        startingPosition = {-1, -1};
        return false;
    }
}

Position Maze::getStartingPosition(){
    return startingPosition;
}

bool Maze::traverse() {
    usleep(100000);
    system("clear");
    render();
    if(tries++ > 4 && currentPosition == startingPosition){
        return false;
    }
    else if(currentPosition != startingPosition &&
        (currentPosition.x == 0 || currentPosition.x == map.size() - 1 ||
        currentPosition.y == 0 || currentPosition.y == map[currentPosition.x].size() - 1)){
        return true;
    }
    else{
        switch (direction){
            case UP:
                if (map[currentPosition.y - 1][currentPosition.x] != '#'){
                    map[currentPosition.y - 1][currentPosition.x] = 'x';
                    currentPosition.y--;
                    direction = RIGHT;
                }
                else {
                    direction = LEFT;
                }
                break;
            case RIGHT:
                if (map[currentPosition.y][currentPosition.x + 1] != '#'){
                    map[currentPosition.y][currentPosition.x + 1] = 'x';
                    currentPosition.x++;
                    direction = DOWN;
                }
                else {
                    direction = UP;
                }
                break;
            case DOWN:
                if (map[currentPosition.y + 1][currentPosition.x] != '#'){
                    map[currentPosition.y + 1][currentPosition.x] = 'x';
                    currentPosition.y++;
                    direction = LEFT;
                }
                else {
                    direction = RIGHT;
                }
                break;
            case LEFT:
                if (map[currentPosition.y][currentPosition.x - 1] != '#'){
                    map[currentPosition.y][currentPosition.x - 1] = 'x';
                    currentPosition.x--;
                    direction = UP;
                }
                else {
                    direction = DOWN;
                }
                break;
        }
        return traverse();
    }
}