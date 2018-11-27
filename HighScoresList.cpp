#include <iostream>
#include <fstream>

#include "highScoresList.h"

using namespace std;
/* Constructor */
highScoresList::highScoresList() {
    load();
}
/* 
 * load()
 * Reads the HIGH_SCORE_FILE and loads the contents of the file
 * into the linked list.
 * If the file does not exist, do nothing. 
 */
void highScoresList::load() {
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

    NodePtr head;
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
void highScoresList::save() {
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
int highScoresList::highestScore(){
    if (head == nullptr)
        return 0;
    return head->val;
}

/*
* s
*/
void highScoresList::print(){
    if (head == nullptr)
        exit(1);
    while (head->next != NULL){
        std::cout << head->name << " " << head->val << endl;
        head = head->next;
    }
}

/*
* prints the names and scores of
* of the top five entries
*/
void highScoresList::printTop5(){
    int count = 0;
    if (head == nullptr);
        exit(1);
    while ((head->next != NULL) or count < 5){
        std::cout << head -> user << " " << head -> val << endl;
        head = head -> next;
        count++;
    }

}

/*
* keeps only the top 10 entries in the list
* and deletes the rest and recycles the memory
*/
void highScoresList::keepTop10(){
    int count = 0;
    if (head == nullptr);
    if (highScoresList.length() < 10)
        exit(1);
    else {
        while (count < 10){
            if (count == 10){
                temp2 = temp;
                NodePtr dis;
                while (temp2 -> next != NULL){
                    dis = temp2 -> next
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
void highScoresList::insert(std::string user, int score){
    Node *tempPtr = new Node;
    tempPtr = head;
    tempPtr -> user = user;
    tempPtr -> val = score;
    Node *after = after(score);
    tempPtr -> next = after -> next;
    after -> next = tempPtr;
}

/*
* clears the linked list and frees all memory
* sets pointer to NULL
*/
void highScoresList::clear(){
    if (head = nullptr)
        exit(1);
    while (head -> next != NULL){
        head -> next = head -> next -> next;
        delete head -> next;
    }
}

/*
* takes a username as an argument and prints out all scores
* for that user in sorted orer
*/
void highScoresList::printUser(std::string user){
    Node *temp = new Node;
    temp = head;
    while (temp -> next != NULL){
        if (temp -> user == user){
            std::cout << user << " " << temp -> val << endl;
        }
        temp = temp -> next;
    }

}

Node *after(int score){
    Node *temp = new Node;
    temp = head;
    while (temp -> next != NULL){
        if (temp -> next = NULL)
            return temp;
        if (((temp -> score) > val) and ((temp -> next -> score) < val))
            return temp;
        temp = temp -> next
    }

}

int highScoresList::length(){
    int count = 0;
    Node *temp = new Node;
    temp = head;
    if (head == nullptr)
        return 0;
    while (head != nullptr){
        count++;
        head = head -> next;
    }
    return count;
}
