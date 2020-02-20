// yoda.cpp
// Purpose: flips word order of 4 word sentence
// Inputs: 4 word sentence
// Outputs: 4 word "flipped" sentence
// Notes: might be possible to make program more general
//	      i.e. >4 or <4 words, concatenation used.
// Author: Alyssa Rose
// Date: 6 - September - 2018
// Comp 11 - HW1

#include <iostream>
#include <string>

using namespace std; 

int main()
{
	string pt1, pt2, pt3, pt4, yodaConcat;

	// gets words individually to concatenate 
	// in opposite order
	cout << "Input a 4 word sentence: \n";
	cin >> pt1;
	cin >> pt2;
	cin >> pt3;
	cin >> pt4;
 
	// concatenates the words from last inputed 
	// to first inputed
	yodaConcat = pt4 + " " + pt3 + " " + pt2 + " "+ pt1;

	cout << yodaConcat << "\n";

	return 0;
	
}