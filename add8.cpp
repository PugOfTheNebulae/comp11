// add8.cpp
// Purpose: Takes in 8 floating point numbers from user and
//			outputs the sum
// Inputs: 8 floating point numbers
// Outputs: sum of the 8 numbers
// Notes: could be done with fewer variables (using for loop)
//		  but used while to make it mutable for more than 8 numbers
// Author: Alyssa Rose
// Date: 6 - September - 2018
// Comp 11 - HW1

#include <iostream>

using namespace std; 

int main()
{
	int numTrack = 8;
	float sumFloat = 0, numIn;

	while(numTrack > 0)
	{
		cout << "Input Number: ";
		cin >> numIn;
		sumFloat = sumFloat + numIn;
		numTrack--;
	}
	cout << "Sum = " << sumFloat << "\n";
}