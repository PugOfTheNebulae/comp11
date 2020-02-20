/*
 * Linked lists of strings.
 *
 * (c) Mark A. Sheldon, Tufts University, Spring 2018
 */

#include <iostream>
#include <stdexcept>

#include "StringLinkedList.h"

using namespace std;

/*
 * Useful functions for allocating a new Node on the heap
 * and initializing it.
 * Native C++ speakers would make Node constructors for this.
 *
 * StringLinkedList:: is required before the function, because
 * C++ hasn't realized this function is in the class yet.
 */
StringLinkedList::Node *StringLinkedList::newNode(string s, Node *next)
{
        Node *result = new Node;

        result->element = s;
        result->next    = next;

        return result;
}

StringLinkedList::Node *StringLinkedList::newNode(string s)
{
        return newNode(s, nullptr);
}

/*
 * Initialize an empty list
 */
StringLinkedList::StringLinkedList()
{
        front = nullptr;
}

/*
 * Reclaim all heap-allocated data associate with list
 */
StringLinkedList::~StringLinkedList()
{
        if (front == nullptr)
                return;
        while (front -> next != NULL){
                Node *tempPtr;
                tempPtr = front;
                front = front -> next;
                delete tempPtr;
                tempPtr = NULL;
        }
        delete front;
}

/*
 * Return true if the list is empty, false otherwise
 */ 
bool StringLinkedList::isEmpty()
{
        if (front == nullptr)
                return true;
        return false;
}

/*
 * Add the given string to the front of the list
 */
void StringLinkedList::addToFront(string s)
{
        Node *tempPtr = new Node;
        tempPtr -> element = s;
        tempPtr -> next = front;
        front = tempPtr;
}

/*
 * Remove the first element (and associated node) from the list
 * Assumes the list is non-empty.
 */
void StringLinkedList::removeFirst()
{
        Node *tempPtr;
        tempPtr = front;
        front = front -> next;
        delete [] tempPtr;
        tempPtr = NULL;
}

/*
 * Return first element in the list.
 * Assume list is non-empty.
 */
string StringLinkedList::firstElement()
{
        return front -> element;
}

/*
 * Print the list elements between square brackets, separated
 * by commas.  E. g.,  [] is the empty list.  
 * [monarch, swallowtail, peacock] is a list of three strings.
 *
 * There is no newline at the end.
 */
void StringLinkedList::print()
{
        string m = " ";
        for (int i = 0; i < length(); i++){
                m += (front -> element);
                front = front -> next;
        }
        cout << "[" << m << "]" << endl;
}

/*
 * Return the length of the list.
 * Do this with a loop here.
 * If you have time, you can re-write this using a recursive helper
 * function that takes a pointer to a Node as an argument.
 */
int StringLinkedList::length()
{
        int count = 0;
        while (front != nullptr){
                count++;
                front = front -> next;
        }
        return count;

        return -1;
}

/*
 * Add the given string to the back of the list.
 */
void StringLinkedList::addToBack(string s)
{
        Node *back = new Node;
        back -> element = s;
        while (front -> next != NULL)
                front = front -> next;
        front -> next = back;
        back -> next = NULL;

}

/*
 * Add the given string to the list so that it is at the given
 * position.  Are you going to check the validity of the position
 * somehow? 
 */
void StringLinkedList::addAtPosition(string s, int position)
{
        Node *insert = new Node;
        insert -> element = s;
        if ((position < 0) or (position > length()))
                exit(1);
        if (position == 1)
                addToFront(s);
        else if (position == length())
                addToBack(s);
        else {
                Node *temp;
                for (int i = 1; i < position - 1; i++){
                        temp = front;
                        front = front -> next;
                }
                temp = insert;
                insert -> next = front;
        }
}

/*
 * Recursively calculate length
 */
int StringLinkedList::length(Node *current)
{
        if (front == NULL)
                return 0;
        return 1 + length(front -> next);
}

/*
 * Print the list in a more (ASCII)artistic fashion.
 * The empty list prints as ()
 * A 3-element list prints like this:
 * "monarch" ~> "swallowtail" ~> "peacock" ~> ()
 */
void StringLinkedList::printArtistically()
{
        printArtistically(front);
}

/*
 * Print a list in the artistic fashion described above starting at
 * given node.
 */
void StringLinkedList::printArtistically(Node *current)
{
        cout << front -> element << " ~> " << printArtistically(front -> next);
}

/*
 * Remove all occurrences of given string, s from the list
 */
void StringLinkedList::remove(string s)
{
        front = removeRec(s, front);
}

/*
 * Remove the first occurrence of s from the list starting at
 * firstNode.
 * Return a pointer to the first node in the updated list.
 * If s does not occur in list, no change is made and firstNode is
 * returned. 
 */
StringLinkedList::Node *StringLinkedList::removeRec(string s, Node *firstNode)
{
        Node *tempPtr;
        if (firstNode -> next -> element){
                tempPtr = firstNode -> next;
                firstNode = tempPtr;
                delete tempPtr;

        }
        else
                return removeRec(s, firstNode -> next);
                
}

