//flights.cpp
//Purpose: to find layover and flight time using smaller functions
//Input: 4 flight times
//Output: layover and total flight time
//Author: Alyssa Rose

#include <iostream>

using namespace std;

int to_min(int hour, int min);
// converts hour and min into min
// returns time in min
void print_time(int m);
// takes in number of min elapsed
// returns 0; prints out elapsed time
int time_elapse(int time1, int time2);
// takes in 2 times 
// returns number of min elapsed between them
int get_hr();
// gets time in hours
int get_min();
//gets time in min
void flight_one();
//prints prompt to get flight 1 times
void flight_two();
//prints prompt to get flight 2 times
int main()
{
	//get flight 1 info, convert to min and find elapsed time
	flight_one();
	int one_dpt = to_min(get_hr(), get_min());
	int one_arv = to_min(get_hr(), get_min());
	int one_elap = time_elapse(one_dpt, one_arv);

	//get flight 1 info, convert to min and find elapsed time
	flight_two();
	int two_dpt = to_min(get_hr(), get_min());
	int two_arv = to_min(get_hr(), get_min());
	int two_elap = time_elapse(two_dpt, two_arv);

	int layover = time_elapse(one_arv, two_dpt);
	print_time(layover);
	print_time(one_elap + two_elap + layover);

	return 0;
}

int to_min(int hour, int min)
{
	int tot_min = (hour * 60) + min;
	return tot_min;
}

void print_time(int m)
{
	int minute = m % 60;
	int hour = (m - minute) / 60;
	cout << hour << " hr " << minute
	<< " min" << endl;
}

int time_elapse(int time1, int time2)
{
	if (time2 < time1){
		time2 = time2 + (24 * 60);
	}
	int elapse = time2 - time1;
	return elapse;
}

int get_hr()
{
	int hour;
	cin >> hour;
	return hour;
}

int get_min()
{
	int min;
	cin >> min;
	return min;
}

void flight_one()
{
	cout << "Flight 1: ";
	return;
}

void flight_two()
{
	cout << "Flight 2: ";
	return;
}