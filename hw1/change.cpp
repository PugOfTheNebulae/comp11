// change.cpp
// Purpose: computes amount of change needed using least # coins
// Inputs: amount of change needed
// Outputs: #quarters, dimes, nickels, pennies needed
// Notes: make program use least amount of change possible
// Author: Alyssa Rose
// Date: 6 - September - 2018
// Comp 11 - HW1

#include <iostream>

using namespace std;

int main()
{
	int changeAmount, quarters, dimes, nickels, pennies;

	cout << "Amount of change in cents? ";
	cin >> changeAmount;

	// Number of quarters, changeAmount = remaining cents
	quarters = (changeAmount - (changeAmount%25))/25;
	changeAmount = changeAmount - (quarters * 25);

	// Number of dimes, changeAmount = remaining cents
	dimes = (changeAmount - (changeAmount%10))/10;
	changeAmount = changeAmount - (dimes * 10);

	// Number of nickles
	nickels = (changeAmount - (changeAmount%5))/5;

	// Remaining cents = # of pennies
	pennies = changeAmount = changeAmount - (nickels * 5);

	cout << quarters <<" quarters, " << dimes << " dimes, "
	<< nickels << " nickels, and " << pennies << " pennies. \n";

	return 0;

}