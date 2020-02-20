#ifndef GAME_H
#define GAME_H

#include <string>

#include "highScoresList.h"

class Game {
    public:
        Game();
        ~Game();
        void play();
    private:
        void print_number(std::string num);
};

#endif
