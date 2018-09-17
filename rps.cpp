// rps.cpp
// Purpose: plays rock, paper scissors with user
// Input: user's play (either r,R,s,S,p,P)
// Output: tells user who won
// Author: Alyssa Rose
// Date: September-14-2018
// Comp11 - hw2

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	//"i" will be used to see if user played r, p, or s
	int i = 0;

	do {
		// gets input and converts input to lowercase
		char userInput, compPlay;
		cout << "Enter play: ";
		cin >> userInput;
		char userInLow = tolower(userInput, locale());

		// picks random value for computers play using rand()
		// and string with all possible plays
		string compOpt = "rps";
		int randPick = rand() % 3;
		compPlay = compOpt[randPick];

		// determines if comp/user played same thing ( = draw)
		if (userInLow == compPlay) {
			if (userInLow == 'r') {
				cout << "Computer chose: Rock. It's a draw!\n" << endl;
			}

			else if (userInLow == 'p') {
				cout << "Computer chose: Paper. It's a draw!\n" << endl;	
			}

			else {
				cout << "Computer chose: Scissors. It's a draw!\n" << endl;
			}

			i++;
		}

		//checks other plays for wins/losses
		else if (userInLow == 'r') {
			if (compPlay == 'p') {
				cout << "Computer chose: Paper. You Lose!\n"<< endl;
			}
			else {
				cout << "Computer chose: Scissors. You Win!\n"<< endl;
			}

			i++;
		}

		else if (userInLow == 'p') {
			if (compPlay == 's') {
				cout << "Computer chose: Scissors. You Lose!\n"<< endl;
			}
			else {
				cout << "Computer chose: Rock. You Win!\n"<< endl;
			}

			i++;
		}

		else if (userInLow == 's') { 
			if (compPlay == 'r') {
				cout << "Computer chose: Rock. You Lose!\n"<< endl;
			}
			else {
				cout << "Computer chose: Paper. You Win!\n"<< endl;
			}

			i++;
		}
		//repeats program with do/while loop if r,p, or s not inputted
		else {
			cout << "Please only play r, p, or s\n" << endl;
		}
	} while (i == 0);

	return 0;
}
