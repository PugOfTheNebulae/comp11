// rps.cpp
// Purpose: plays rock, paper scissors with user
// Input: user's play (either r,R,s,S,p,P)
// Output: tells user who won
// Notes: I kept the computer's play in terms of  
//letters for conditionals (comparing plays)   
//and for stylistic purposes.		  
//Seperate if statements were also
//used to make code more readable.
// Author: Alyssa Rose
// Date: September-14-2018
// Comp11 - hw2

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	//"i" will be used to see if user played 
	//r, p, or s and repeats loop if i == 0
	//(player didn't play one of the options)
	int i = 0;

	do {
		// gets input and converts input to 
		//lowercase to make conditionals
		// easier to write and work with
		char user_input;
		cout << "Enter play: ";
		cin >> user_input;
		char user_in_low = tolower(
			user_input, locale());

		// picks random value for computer's play using 
		//rand() and string with 
		//all possible plays; letters used for comp_play
		//for comparison and style    
		string comp_options = "rps";
		srand(time(0));
		int rand_pick = rand() % 3;
		char comp_play = comp_options [rand_pick];

		// determines if comp/user played same 
		//thing ( = draw)
		if (user_in_low == comp_play) {
			if (user_in_low == 'r') {
				cout << "Computer chose: Rock."
				<< " It is a draw!\n";
			}

			else if (user_in_low == 'p') {
				cout << "Computer chose: Paper."
				<< " It is a draw!\n";	
			}

			else {
				cout << "Computer chose: Scissors."
				<< " It is a draw!\n";
			}

			i++;
		}

		//checks other plays for wins/losses
		else if (user_in_low == 'r') {
			if (comp_play == 'p') {
				cout << "Computer chose: Paper."
				<< " You Lose!\n";
			}
			else {
				cout << "Computer chose: Scissors."
				<< " You Win!\n";
			}

			i++;
		}

		else if (user_in_low == 'p') {
			if (comp_play == 's') {
				cout << "Computer chose: Scissors."
				<< " You Lose!\n";
			}
			else {
				cout << "Computer chose: Rock." 
				<< " You Win!\n";
			}

			i++;
		}

		else if (user_in_low == 's') { 
			if (comp_play == 'r') {
				cout << "Computer chose: Rock."
				<< " You Lose!\n";
			}
			else {
				cout << "Computer chose: Paper."
				<< " You Win!\n";
			}

			i++;
		}
		//repeats program with do/while loop if r,p, 
		//or s not inputted
		else {
			cout << "Please only play r, " <<
			"p, or s\n";
		}
	} while (i == 0);

	return 0;
}
