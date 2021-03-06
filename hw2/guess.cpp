// guess.cpp
// Purpose: Generates random number between 5-15 inclusive
//			and gives the user 3 chances to guess correctly
// Input: user guess
// Output: whether guess is too low, too high, or correct
// Author: Alyssa Rose
// Date: September-14-2018
// Comp11 - hw2

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	// rand() creates random # and % 11 + 5 adjusts to  5-15 (inclusive) 
	// srand(time(0)) used to make rand not output same number
	int guess, i = 0;
	srand(time(0));
	int rand_number = rand() % 11 + 5;

	do {
		cout << "Enter guess between 5 and 15: ";
		cin >> guess;

		// break quits loop if user guesses correctly
		if (guess == rand_number) {
			cout << "You guessed correctly!\n";
			break;
		}

		if (guess > rand_number) {
			cout << "Too high!\n";
		}
		if (guess < rand_number) {
			cout << "Too low!\n";
		}

		i++;
	} while (i < 3);
	
	//conditional used so statement isn't printed if user
	// guesses in less than three tries
	if (i == 3) {
		cout << "You ran out of guesses!\n";
	}

	return 0;
}