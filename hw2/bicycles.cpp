// bicycles.cpp
// Purpose: tell the user how many bikes they can make given
//			a number of wheels, frames and links
// Input: # of wheels, frames, and links
// Output: # of bikes that can be made
// Author: Alyssa Rose
// Date: September-14-2018
// Comp11 - hw2

#include <iostream>

using namespace std;

int main()
{
	int wheels, frames, links;
	int bikes = 0;

	// checks for valid input by seeing if it is 
	//less than zero
	cout << "Enter number of wheels: ";
	cin >> wheels;

	if (wheels < 0) {
		cout << "Number of wheels must be greater than zero: ";
		cin >> wheels;
	}

	cout << "Enter number of frames: ";
	cin >> frames;

	if (frames < 0) {
		cout << "Number of frames must be greater than zero: ";
		cin >> frames;
	}

	cout << "Enter number of links: ";
	cin >> links;

	if (links < 0) {
		cout << "Number of links must be greater than zero: ";
		cin >> links;
	}

	// checks if enough parts for 1 bike; if yes 
	//determines how many more can be made using loop
	if ((frames >= 1) && (wheels >= 2) && (links >= 50)) {
		while ((frames >= 1) && (wheels >= 2) && (links >= 50))
		{
			frames--;
			wheels = wheels - 2;
			links = links - 50;
			bikes++;
		}

		cout << bikes << " bikes, leftovers: " << frames << 
		" frames, "
		<< wheels << " wheels, and " << links << " links.\n";

	}

	// determines left over amount from readjusted values
	// from loop OR from input if 1 bike wasn't made.
	else {
		cout << "leftovers: " << wheels << " wheels," << frames <<
		" frames, and " << links << " links." << endl;
	}

	return 0;
}
