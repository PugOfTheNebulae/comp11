/*
* Project 2: 2048
* highScoresList.cpp
* Author : Alyssa Rose
* Date : 12-1-2018
* Purpose: implementation file for
*   highScoreList class
* Notes: insert function longer than 30 
*   lines, but further modularity within the func
*   would've not made complete sense do to
*   structure of the function
* Known Bugs: none
*/
#include <iostream>
#include <fstream>
#include <string>

#include "highScoresList.h"

using namespace std;

/*
* HighScoresList()
* Purpose: std constructor
*/
HighScoresList::HighScoresList() {
    head = NULL;
    load();
}

/*
* ~HighScoresList()
* Purpose: standard deconstructor
*/
HighScoresList::~HighScoresList(){
    clear();
}

/* 
 * load()
 * Purpose: Reads the HIGH_SCORE_FILE and loads the contents 
 * of the file into the linked list.
 * If the file does not exist, do nothing. 
 */
void HighScoresList::load() {
    ifstream inFile;
    inFile.open(HIGH_SCORE_FILE);
    if (not inFile) {
        head = NULL;
        exit(1);
    }
    string user;
    int score;
    while (inFile >> user) {
        if (user == SENTINEL) 
            break;

        inFile >> score;
        insert(user, score);
    }
    inFile.close();
}

/* 
 * save()
 * Purpose: Writes the names and scores to the HIGH_SCORE_FILE, 
 * followed by the sentinel
 * This will overwrite what was originally in HIGH_SCORE_FILE.
 */
void HighScoresList::save() {
    ofstream outFile;
    outFile.open(HIGH_SCORE_FILE);
    
    Node *temp = head;
    while (temp != NULL){
    //will print out all the users in the list
        outFile << temp -> user << " " << temp -> val << endl;
        temp = temp -> next;
    }
    outFile << SENTINEL << endl;
    outFile.close();
}   

/*
* highestScore()
* Purpose: returns an int representing the highest score in the list
* Returns :int of the length
*/
int HighScoresList::highestScore(){
    if (head == NULL){
        return 0;
    }
    return head -> val;
}

/*
* print()
* Purpose: Print out the things in the linked list
* Effects: None
*/
void HighScoresList::print(){
    Node *temp = head;
    if (head == NULL)
        return;
    while (temp != NULL){
        cout << temp -> user << " " << temp -> val << endl;
        temp = temp -> next;
    }
}

/*
* printTop5()
* Purpose: prints the names and scores of
* of the top five entries
*/
void HighScoresList::printTop5(){
    int count = 0;
    Node *temp;
    temp = head;
    if (head == NULL)
        return;
    if (length() <= 5){
        print();
    }
    else{
        while (count <= 4){
            cout << temp -> user << " " << temp -> val << endl;
            temp = temp -> next;
            count++;
        }
    }
}

/*
* keepTop10()
* Purpose: keeps only the top 10 entries in the list
* and deletes the rest and recycles the memory
*/
void HighScoresList::keepTop10(){
    int count = 0;
    if (length() <= 10)
        return;
    else {
        Node *temp;
        temp = head;
        Node *temp2 = temp -> next;
        Node *dis;
        while (count < 9){
            temp = temp -> next;
            count++;
            cout << count << endl;
            cout << temp -> user << endl;
        }
        dis = temp -> next;
        while (temp2 != NULL){
            temp2 = dis -> next;
            delete dis;
            dis = temp2;
        }
        temp -> next = NULL;
        cout << temp -> user << endl;
        delete temp2;
    }

}

/*
* clear()
* Purpose: clears the linked list and frees all memory
* sets pointer to NULL
*/
void HighScoresList::clear(){
    if (head == NULL)
        return;
    Node *temp = head;
    Node *forward = temp -> next;
    while (forward != NULL){
        delete temp;
        temp = forward;
        forward = forward -> next;
    }
    head = NULL;
    delete temp;
}

/*
* printUser(string user)
* Purpose: takes a username as an argument and prints out 
* all scores for that user in sorted orer
*/
void HighScoresList::printUser(string user){
    if (head == NULL)
        return;
    Node *temp = new Node;
    temp = head;
    while (temp -> next != NULL){
        if (temp -> user == user){
            cout << user << " " << temp -> val << endl;
        }
        temp = temp -> next;
    }
}

/* 
* length()
* Purpose: finds the length of the linked list
* Returns: int representation of the length of the linked list
*/
int HighScoresList::length(){
    int count = 0;
    Node *temp = head;
    while (temp != NULL){
        temp = temp -> next;
        count++;
    }
    return count;
}

/* 
* insert(string user, int score)
* Purpose: insert a node in order
* of decreasing score
* Return: Nothing
*/
void HighScoresList::insert(string user, int score){
    Node *temp = newNode(user, score);
    if (head == NULL){
        temp -> next = NULL;
        head = temp;
        return;
    }
    if ((head -> val) <= score){
        temp -> next = head;
        head = temp;
        return;
    }
    Node *prev;
    Node *curr;
    prev = head;
    curr = prev -> next;
    if (curr == NULL){
        prev -> next = temp;
        temp -> next = NULL;
        return;
    }
    else {
        while (curr != NULL){
            if ((curr -> val) <= score){
                prev -> next = temp;
                temp -> next = curr;
                break;
            }
            prev = curr;
            curr = curr -> next;
        }
        if (curr == NULL){
            prev -> next = temp;
            temp -> next = NULL;
        }
    }
}

/*
* newNode(string user, int score)
* Purpose: creates a new node given a core and a user's name
* Returns: pointer to the new node
*/
HighScoresList::Node *HighScoresList::newNode(string user, int score){
    Node *result = new Node;
    result -> user = user;
    result -> val = score;
    result -> next = NULL;
    return result;
}
