#include <iostream>
using namespace std;

int main()
{
	int x;
	int *p;
	int *a;
	//if you dereferenced twice, would get an int
	int **z;
/*******************************/
	cout << "Stage One" << endl;
	x = 3;
	p = &x;
	cout << "x: " << x << endl;
	// 3
	cout << "p: " << p << endl;
	// address of x
	cout << "*p: " << *p << endl;
	// 3

/*********************************/
	cout << "Stage Two" << endl;
	*p = *p - 1;
	// should equal 2 now
	cout << "x: " << x << endl;
	// 2
	cout << "*p: " << *p << endl;
	// 2

/*********************************/
	cout << "Stage Three" << endl;
	a = p;
	// a = address of x
	cout << "*a: " << *a << endl;
	// 2
	cout << "*p: " << *p << endl;
	// 2
	cout << "x: " << x << endl;
	// 2

/*******************************/
	cout << "Stage Four" << endl;
	*a = *p - 1;
	// *a = 1
	cout << "*a: " << *a << endl;
	cout << "*p: " << *p << endl;
	// should equal 1?, it is changing it all
	// by indirection

/********************************/
	cout << "Stage Five" << endl;
	cout << "z = &p" << endl;
	z = &p;
	cout << "z: " << z << endl;
	cout << "*z: " << *z << endl;
	// gets value of p
	cout << "**z: " << **z << endl;
	// 1

/*********************************/
	cout << "Stage 6" << endl;
	// assigns p the location 0x04 (loc 4)
	p = (int *) 4; 
	cout << *p << endl;


	return 0;

}