// int_to_string.cpp
//converts an integer to a string
//Author: Alyssa Rose

#include <iostream>
#include <cmath>
using namespace std;

string int_to_string (int n, int length, string m);
// converts integer val to string
//takes in integer, the length of the int and
//an empty string to index into to make the 
//new string
int get_digit_zero (int m);
//gets the length of the integer
//takes int, returns length of int
string make_empty(int k);
//creates string of * to index into
//takes in length of number and returns
//string of same size full of *

int main()
{
	//expect 123456 as a string
	int k = get_digit_zero(123456);
	string ans = int_to_string (123456, k, make_empty(k));
	cout << ans << endl;

	//expect 2323 as a string
	int m = get_digit_zero(2323);
	string ans2 = int_to_string (2323, m, make_empty(m));
	cout << ans2 << endl;

	//expect 245 as a string
	int n = get_digit_zero(245);
	string ans3 = int_to_string (245, n, make_empty(n));
	cout << ans3 << endl;

	//expect 505 as a string
	int p = get_digit_zero(505);
	string ans4 = int_to_string (505, p, make_empty(p));
	cout << ans4 << endl;

	return 0;
}

string int_to_string(int n, int length, string m)
{
	if (n < 10){
		m[0] = n + '0';
		return m;
	}
	else {
		int current = n % 10;
		m[length - 1] = current + '0';
	}
	return int_to_string(n/10, length - 1, m);
}

int get_digit_zero (int m)
{
	int length = 1;
	while(m /= 10){
		length++;
	}
	return length;
}

string make_empty(int k){
	string h;
	while(k > 0){
		h += '*';
		k--;
	}
	return h;
}
