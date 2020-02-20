#include <iostream>
#include <string>
using namespace std;

string int_to_string(int m);

int main()
{
	cout << int_to_string(1234) << endl;
	return 0;
}

string int_to_string(int m)
{
	return m + '\0';
}