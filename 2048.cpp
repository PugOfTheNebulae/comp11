/*
 * Driver for 2048 
 * COMP11 Spring 2018
 */

#include <iostream>

#include "game.h"

int main() {
    Game game;
    game.play();
    return 0;
}

/*
* compile with: clang++ -Wall -Wextra -std=c++11 -o 2048 2048.cpp game.cpp highScoresList.cpp int-string.cpp
* ./2048
