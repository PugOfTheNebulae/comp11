// dictionary.cpp
//Purpose:
//Date: 22-september-2018
//Author: Alyssa Rose

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void dictionary();
//checks word is in dictionary and calls 
//definition functions
void var_def();
//prints variable definition
void func_def();
//prints function definition
void rec_def();
//prints recursive definition
void cond_def();
//prints conditional definition
void comp11_def();
//prints comp11 definition

int main()
{
	dictionary();
	return 0;
}

void dictionary()
{
	string word_input;
	cout << "Input word: ";
	cin >> word_input;
	//forces everything to lower case using transform
	transform(word_input.begin(), word_input.end(), 
		word_input.begin(), ::tolower);	
	if (word_input == "variable")
		var_def();
	else if (word_input == "function")
		func_def();
	else if (word_input == "recursion")
		rec_def();
	else if (word_input == "conditional")
		cond_def();
	else if (word_input == "comp11")
		comp11_def();
	else
		cout << "Definition Not Found\n";		
}
void var_def()
{
	cout << "thing that stores values of different data types" << endl;
}
void func_def()
{
	cout << "thing that does a certain task" << endl;
}
void rec_def()
{
	cout << "thing that refers to itself in definition" << endl;
}
void cond_def()
{
	cout << "makes decisions and executes based on bool values" << endl;
}
void comp11_def()
{
	cout << "intro cs class at Tufts University" << endl;
}
