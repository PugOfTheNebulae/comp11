/* 
* Project 2: 2048
* testHighScoreList.cpp
* Author: Alyssa Rose
* Date: 11-25-2018
* Purpose: tester file for highScoreList
* Notes: none
* Known Bugs: none
*/
#include <iostream>
#include "highScoresList.h"

using namespace std;
int main() {
	HighScoresList highScore;
	cerr << highScore.highestScore() << endl;
	cerr << "high score" << endl;
	highScore.print();
	cerr << "print" << endl;
	highScore.printTop5();
	cerr << "top 5" << endl;
	highScore.insert("Jane", 7800);
	cerr << "insert" << endl;
	highScore.keepTop10();
	cerr << "top ten" << endl;
	highScore.print();
	cerr << "print" << endl;
	highScore.save();
	cerr << "save" << endl;
	return 0;

}