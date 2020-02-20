// guess.cpp
// Purpose: Generates random number between 5-15 inclusive
//			and gives the user unlimited chances to guess correctly
// Input: user guess
// Output: whether guess is too low, too high, or correct
// Author: Alyssa Rose
// Date: October-6-2018
// Comp11 - hw4

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	// rand() creates random # and % 11 + 5 adjusts to  5-15 (inclusive) 
	// srand(time(0)) used to make rand not output same number
	int guess = 0, i = 0;
	srand(time(0));
	int rand_number = rand() % 11 + 5;

	while (guess != rand_number){
		cout << "Enter guess between 5 and 15: ";
		cin >> guess;

		if (guess > rand_number) {
			cout << "Too high!\n";
		}
		if (guess < rand_number) {
			cout << "Too low!\n";
		}

		i++;
	}
	cout << "You guessed the number in " << i << " guesses!" << endl;
	return 0;
}