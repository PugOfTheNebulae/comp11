#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// int largest(int arr[], int len, int temp);

// int main()
// {
// 	int len = 12;
// 	int arr1[12] = {20, 9, 15, 5, 13, 3, 2, 3, 7, 4, 13, 7};
// 	int temp = arr1[len - 1];
// 	int lrg_val = largest(arr1, len - 1, temp);
// 	cout << lrg_val << endl;
// 	return 0;
// }

// int largest(int arr[], int len, int temp)
// {
// 	if (len == 0)
// 		return temp;
// 	else{
// 		if (arr[len-1] > temp)
// 			temp = arr[len - 1];
// 		return largest(arr, len - 1, temp);
// 	}
// }
// int main()
// {
// 	int num, power, mod;
// 	cout << "insert number: ";
// 	cin >> num;
// 	cout << "power: ";
// 	cin >> power;
// 	cout << "mod: ";
// 	cin >> mod;
// 	for (int i = 1; i <= power; i++){
// 		int res = (int) pow(num, i);
// 		cout << res%mod << endl;
// 	}
// 	return 0;
// }
// int factorial (int k);
// int main()
// {
// 	int row;
// 	cout << "Input row number: ";
// 	cin >> row;

// 	for (int j = 0; j <= row; j++){
// 			cout << (factorial(row)/(factorial(j) * factorial(row - j)))%3 << "  ";
// 		}
	
// 	cout << endl;
// 	return 0;
// }
// int factorial (int k){
// 	int fac = 1;
// 	for (int i = 0; i < k; i++){
// 		fac *= (k - i);
// 	}
// 	return fac;
// }

//Alyssa Rose
//Discrete HW 10
//Bonus problem
int gcd (int a, int b, int *pt);
int main()
{
	int *pt1 = new int;
	int *pt2 = new int;
	int *pt3 = new int;
	cout << "GCD: " << gcd(25,20, pt1) <<" Calls: "<< *pt1 << endl;
	cout << "GCD: " << gcd(54321, 50, pt2) <<" Calls: "<< *pt2 << endl;
	cout << "GCD: " << gcd(29341, 1739, pt3) <<" Calls: "<< *pt3 << endl;
	delete pt1;
	delete pt2;
	delete pt3;
	return 0;
}

int gcd (int a, int b, int *pt)
{
	int current, call = 0;
	while (b != 0){
		current = a%b;
		a = b;
		b = current;
		call++;
	}
	*pt = call;
	return a;
}


