//==============================================================
// Filename : maze.hpp
// Authors : Jibbe Andringa S2336219
// Group : 12
// License : N.A.
// Description : Header file of the Maze class
//==============================================================

#ifndef PROGRAMMING2_MAZE_HPP
#define PROGRAMMING2_MAZE_HPP

#include <array>
#include <iostream>
#include <unistd.h>

/**
* @brief Enum representing the four possible directions.
*/
enum Direction {
    UP, /**< Up direction. */
    RIGHT, /**< Right direction. */
    DOWN, /**< Down direction. */
    LEFT /**< Left direction. */
};

/**
* @brief Struct representing a position in the map.
*/
struct Position {
    int x; /**< x-coordinate of the position. */
    int y; /**< y-coordinate of the position. */

    /**
    * @brief Overloaded not equal operator to compare two positions.
    * @param pos The position to compare with.
    * @return True if either x or y coordinate is not equal, false otherwise.
    */
    bool operator!=(Position pos) {
        return this->x != pos.x || this->y != pos.y;
    }

    /**
     * @brief Overloaded equal operator to compare two positions.
     * @param pos The position to compare with.
     * @return True if both x and y coordinates are equal, false otherwise
     */
    bool operator==(Position pos) {
        return this->x == pos.x && this->y == pos.y;
    }
};

/**
* @brief Class implementation of the Maze game.
* This class contains a two dimensional array of characters representing the map of the maze, a starting position,
* a current position, and a direction. The class provides methods to render the map, get the starting position, traverse the maze,
* and determine the starting position.
*/
class Maze {
    std::array<std::array<char, 12>, 12> map; /**< Map of the maze represented as a two dimensional array of characters. */
    Position startingPosition = {0, 0}; /**< Starting position of the maze. */
    Position currentPosition; /**< Current position of the traverser in the maze. */
    Direction direction = UP; /**< Direction of the traverser in the maze. */
    int tries = 0; /**< Amount of tried steps from the starting position */

    /**
    * @brief A recursive function to determine the starting position of the maze.
    * @param pos The current position to check.
    * @return True if the starting position is found, false otherwise.
    */
    bool determineStart(Position pos);

public:
    /**
     * @brief Constructor for the Maze class.
     * @param map Map of the maze represented as a two dimensional array of characters.
     */
    Maze(std::array<std::array<char, 12>, 12> map);

    /**
    * @brief Renders the map of the maze.
    */
    void render();

    /**
    * @brief Gets the starting position of the maze.
    * @return The starting position.
    */
    Position getStartingPosition();

    /**
    * @brief Traverses the maze.
    * @return True if the traverser has reached the end of the maze, false otherwise.
    */
    bool traverse();
};


#endif //PROGRAMMING2_MAZE_HPP
