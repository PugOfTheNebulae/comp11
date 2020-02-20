// most_common_int.cpp
// finds the most common integer in an array

#include <iostream>
using namespace std;

void foo(int array[], int array_len);
int main()
{
	int array_len = 5;
	int array[5] = {1, 4, 5, 2, 1}; 
	foo(array, array_len);

	int array_len2 = 7;
	int array2[7] = {1, 1, 2, 2, 2, 2, 5}; 
	foo(array2, array_len2);

	int array_len3 = 7;
	int array3[7] = {1, 1, -2, -2, -2, -2, -2}; 
	foo(array3, array_len3);

	int array_len4 = 4;
	int array4[4] = {0, 0, 0, 1}; 
	foo(array4, array_len4);
}

void foo(int array[], int array_len)
{
	int index = 0;
	int amt = 0;
	for (int i = 0; i < array_len; i++){
		int cnt = 0;
		int current = array[i];
		for (int k = 0; k < array_len; k++){
			if (array[k] == current)
				cnt++;
		}
		if ((cnt > amt) or ((cnt == amt) and (array[index] > 
			array[i]))){
			amt = cnt;
			index = i;
		}
	}
	cout << array[index] << endl;
}