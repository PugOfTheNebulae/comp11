/*
* Project 2: 2048
* game.h
* Author: Alyssa Rose
* Date: 12-1-2018
* Purpose: header file for game.cpp
* Notes: none
* Known Bugs: none
*/

#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>

#include "HighScoresList.h"

class Game {
    public:
        Game();
        ~Game();
        void play();
    private:
    	HighScoresList highScores;
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
        void play_other(std::string in);
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
