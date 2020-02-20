//pattern.cpp
//Purpose: output woven pattern of words written
// on n lines
//input: 2 strings, one int
//output: nothing; void function
//25-September-2018
//Author: Alyssa Rose
//Notes: considered making function to create the in line string 
//	     but decided not to since it's always (s1 + s2) * 5 or
//		 (s2 + s1) * 5
#include <iostream>
#include <string>
using namespace std;

void output_pattern(string s1, string s2, int n);
// prints the strings s1 and s2 for n lines
//input: 2 string and an integer
//output: nothing, only prints to screen
string get_string();
// used to get string value from user
// returns string
int get_int();
// used to get int value from user
// returns int
int main()
{
	output_pattern(get_string(), get_string(), get_int());
	return 0;
}

void output_pattern(string s1, string s2, int n)
{
	if (n == 0){
		return;
	}
	
		else if (n % 2 == 0)
		{
			cout << s2 + s1 + s2 + s1 + s2 + s1 + s2 + 
			s1 + s2 + s1 << endl;
			return output_pattern(s1, s2, n-1);
		}
		else
		{
			cout << s1 + s2 + s1 + s2 + s1 + s2 + s1 + 
			s2 + s1 + s2 << endl;
			return output_pattern(s1, s2, n-1);
		}
	
}

string get_string()
{	
	string string_in;
	cout << "Enter word: ";
	cin >> string_in;
	return string_in;
}

int get_int()
{	
	int int_in;
	cout << "Enter number: ";
	cin >> int_in;
	return int_in;
}

