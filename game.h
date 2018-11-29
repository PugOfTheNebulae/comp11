// Alyssa Rose

#ifndef GAME_H
#define GAME_H

#include <string>

#include "HighScoresList.h"

class Game {
    public:
        Game();
        ~Game();
        void play();
    private:
    	HighScoresList highScore;
    	int dim;
        int score;
        std::string **board;
        int Row;
        int Col;
        
        void print_number(std::string num);
        std::string rando_num();
        void rando_loc();
        
        void prt_start();
        void new_brd();
        void prt_brd();
        bool filled();
        bool make_mv();
        void play_other(std::string in, std::string in2);
        void end_game();

        void left_push();
        void right_push();
        void down_push();
        void up_push();

        void merge_left();
        void merge_right();
        void merge_down();
        void merge_up();

        void play_left();
        void play_right();
        void play_up();
        void play_down();

};

#endif
