// flights.cpp
// Purpose: determines if 2 flights can be connecting flights
// Input: arrival and departure times
// Output: layover time and total travel times
// Author: Alyssa Rose
// Date: September-14-2018
// Comp11 - hw2

#include <iostream>
using namespace std;

int main()
{
	int one_depart_hr, one_depart_min, one_arrive_hr, one_arrive_min;
	int two_depart_hr, two_depart_min, two_arrive_hr, two_arrive_min;

	cout << "Flight 1: ";
	cin >> one_depart_hr >> one_depart_min >> one_arrive_hr >> one_arrive_min;

	// converts everything to minutes for first flight
	int one_depart = (one_depart_hr * 60) + one_depart_min;
	int one_arrive = (one_arrive_hr * 60) + one_arrive_min;
	
	cout << "Flight 2: ";
	cin >> two_depart_hr >> two_depart_min >> two_arrive_hr >> two_arrive_min;

	// converts everything to minutes for second flight
	int two_depart = (two_depart_hr * 60) + two_depart_min;
	int two_arrive = (two_arrive_hr * 60) + two_arrive_min;
	
	// deals with next day flights by adding full day 
	// in min to the next day flight (24 * 60)
	if (one_arrive < one_depart) {
		one_arrive = one_arrive + (24 * 60);
	}
	if (two_depart < one_arrive) {
		two_depart = two_depart + (24 * 60);
	}
	if (two_arrive < two_depart) {
		two_arrive = two_arrive + (24 * 60);
	}

	// determines layover from flight differences, modulus
	// operator and division to convert min to hour/min
	int flight_one = one_arrive - one_depart;
	int flight_two = two_arrive - two_depart;
	int lay_min = (two_depart - one_arrive) % 60;
	int lay_hr = ((two_depart - one_arrive) - lay_min) / 60;

	// same process as above to get total flight time
	int total_min = (flight_one + flight_two + lay_min + (lay_hr * 60)) % 60;
	int total_hr = ((flight_one + flight_two + lay_min + (lay_hr * 60)) - total_min) / 60;

	cout << "Layover: " << lay_hr << " hour " << lay_min << " min\n";
	cout << "Total: " << total_hr << " hour " << total_min << " min\n";
	
	return 0;
}