#include <iostream>
#include <fstream>

#include "highScoresList.h"

using namespace std;
/* Constructor */
HighScoresList::HighScoresList() {

    // TODO: initialize any private attributes you may have

    load();
}
/* 
 * load()
 * Reads the HIGH_SCORE_FILE and loads the contents of the file
 * into the linked list.
 * If the file does not exist, do nothing. 
 */
void HighScoresList::load() {
    ifstream inFile;
    inFile.open(HIGH_SCORE_FILE);
    if (not inFile) {
        return;
    }
    string user;
    int score;

    while (inFile >> user) {
        if (user == SENTINEL) 
            break;

        inFile >> score;
        // TODO: insert user and score to the end of your linked list
    }

    inFile.close();
}

/* 
 * save()
 * Writes the names and scores to the HIGH_SCORE_FILE, followed by the 
 * sentinel.
 * This will overwrite what was originally in HIGH_SCORE_FILE.
 */
void HighScoresList::save() {
    ofstream outFile;
    outFile.open(HIGH_SCORE_FILE);
    

    // TODO: write the users and scores to outFile

    outFile << SENTINEL << endl;
    outFile.close();
}   

