#include <iostream>
#include <fstream>

#include "highScoresList.h"

using namespace std;
/* Constructor */
HighScoresList::HighScoresList() {
    head = nullptr;
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
        head -> next = NULL;
        head -> next -> user = "";
        head -> next -> val = 0;
        return;
    }
    string user;
    int score;

    while (inFile >> user) {
        if (user == SENTINEL) 
            break;

        inFile >> score;

        head -> next = new Node;

        head -> next -> user = user;
        head -> next -> val = score;
        head = head -> next;
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
    
    //will print out all the users in the list
    outFile << highScoresList.print() << endl;

    outFile << SENTINEL << endl;
    outFile.close();
}   

/*
* returns an int representing the highest score in the list
*/
int HighScoresList::highestScore(){
    if (head == nullptr)
        return NULL;
    return head->val;
}

/*
* s
*/
void HighScoresList::print(){
    if (head == nullptr)
        return;
    while (head->next != NULL){
        std::cout << head->user << " " << head->val << endl;
        head = head->next;
    }
}

/*
* prints the names and scores of
* of the top five entries
*/
void HighScoresList::printTop5(){
    int count = 0;
    if (head == nullptr)
        return;
    while ((head->next != NULL) or count < 5){
        std::cout << head->user<< " " << head->val << endl;
        head = head->next;
        count++;
    }

}

/*
* keeps only the top 10 entries in the list
* and deletes the rest and recycles the memory
*/
void HighScoresList::keepTop10(){
    int count = 0;
    if (highScoresList.length() < 10)
        exit(1);
    else {
        Node *temp = new Node;
        temp = head;
        Node *temp2 = new Node;
        while (count < 10){
            if (count == 10){
                temp2 = temp;
                Node *dis = new Node;
                while (temp2 -> next != NULL){
                    dis = temp2 -> next;
                    temp2 -> next = dis -> next;
                    delete dis;
                }
            }
            count++;
        }
    }

}

/*
* takes a string name and an int score
* and creates a new node for this entry
* and inserts it into the linked list sorted
* in decreasing order of scores
* if scores are tied, the new node comes first
*/
void HighScoresList::insert(std::string user, int score){
    Node *tempPtr = new Node;
    tempPtr -> user = user;
    tempPtr -> val = score;
    if (head == nullptr)
        head = temp;
    Node *after = after(score, head);
    tempPtr -> next = after -> next;
    after -> next = tempPtr;
}

/*
* clears the linked list and frees all memory
* sets pointer to NULL
*/
void HighScoresList::clear(){
    if (head == nullptr)
        return;
    while (head -> next != NULL){
        head -> next = head -> next -> next;
        delete head -> next;
    }
}

/*
* takes a username as an argument and prints out all scores
* for that user in sorted orer
*/
void HighScoresList::printUser(std::string user){
    if (head == nullptr)
        return;
    Node *temp = new Node;
    temp = head;
    while (temp -> next != NULL){
        if (temp -> user == user){
            std::cout << user << " " << temp -> val << endl;
        }
        temp = temp -> next;
    }

}

HighScoresList::Node * HighScoresList::after(int score){
    Node *temp = new Node;
    temp = head;

    while (temp -> next -> next != NULL){
        if (temp -> next == NULL)
            return temp;
        if (((temp -> val) > score) and ((temp -> next -> val) < score))
            return temp;
        temp = temp -> next;
    }

}

int HighScoresList::length(Node *head){
    int count = 0;
    while (head != nullptr){
        count++;
        head = head -> next;
    }
    return count;
}
