// string_to_int.cpp
// converts string to the integer value
// author: Alyssa Rose

#include <iostream>
using namespace std;

int string_to_int(string n);
// takes in string and returns the numbers in the string
//as integers by putting them into a string first and then 
//converting the string character by character into integers.

int main()
{
	//returns 1236
	cout << string_to_int("123ab6") <<endl;
	//returns 1100
	cout << string_to_int("comp11issoc00L") << endl;
	//returns 8
	cout << string_to_int("ericmetajisgr8") << endl;
	//returns 15
	cout << string_to_int("can0L15") << endl;
}
int string_to_int(string n){
	int i = 0;
	string m = "";
	while (n[i] != '\0'){
		if ((int(n[i]) < 58) and (int(n[i]) > 47))
			m = m + n[i];
		i++;
	}
	int int_form = 0;
	int to_int = 0;
	for (int i = 0; m[i] != '\0'; i++){
		to_int = m[i] - '0';
		int_form = int_form * 10 + to_int;
	}
	return int_form;
}