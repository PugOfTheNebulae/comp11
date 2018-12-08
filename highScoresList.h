/*
* Project 2: 2048
* highScoreList.h
* Author: Alyssa Rose
* Date: 12-1-2018
* Purpose: header file for highScoreList.cpp
* Notes: none
* Known Bugs: none
*/

#ifndef HIGHSCORESLIST_H
#define HIGHSCORESLIST_H

#include <string>
#include <iostream>

class HighScoresList {
    public:
        HighScoresList();
        ~HighScoresList();
        void save();
        int highestScore();
        void print();
        void printTop5();
        void keepTop10();
        void printUser(std::string user);
        void insert(std::string user, int score);
        void clear();

    private:
        const std::string SENTINEL = "-1";
        const std::string HIGH_SCORE_FILE = "highScores.txt";
        struct Node
        {
            std::string user;
            int val;
            Node *next;
        };
        Node *head;
        void load();
        int length();
        Node *newNode(std::string user, int val);
};


#endif

