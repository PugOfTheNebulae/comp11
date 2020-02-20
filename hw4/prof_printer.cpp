// prof_printer.cpp
// Purpose: prints out Sam if divisible by 3 and
// prints out Mark if divisible by 5
// Author: Alyssa Rose
#include <iostream>
using namespace std;

int main()
{
	int num[100];
	for(int j = 0; j < 100; j++){
		num[j] = j + 1;
	}
	int i = 0;
	while (i < 100) {
		if ((num[i] % 3 == 0) or (num[i] % 5 == 0)){
			if((num[i] % 3 == 0) and (num[i] % 5 == 0))
				cout << "SamMark" << endl;
			else if (num[i] % 3 == 0)
				cout << "Sam" << endl;
			else
				cout << "Mark" << endl;
		}
		else{
			cout << i + 1 << endl;
		}
		i++;
	}
	return 0;
}