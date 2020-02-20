/*
 * realtor.cpp
 * compile with:
 *     clang++ -Wall -Wextra -std=c++11 -o 
 *       realtor realtor.cpp
 * Edited by: Alyssa Rose
 * Date: October 12, 2018
 */

#include <iostream>
#include <fstream>

using namespace std;


struct House {
    int bed;
    float bath;
    int floor;
    string address;
    bool occup;
};

struct Client_Data {
    int floor_des;
    int bed_des;
    float bath_des;
};

const int NUM_HOUSES = 10;

// Function prototypes
void print_house(House h);
//uses info from the struct to print to screen
//info about the house. Takes in h of type struct House
void load_array(House m[], string f, int size);
//reads in file containing information about the 
//housing 
int calculate_cost(House g);
//calculates the cost of a house by certain
//features. Takes in g of type struct House
//and returns the cost
float calculate_rental_cost(House d);
//calculates the rental cost of a house by certain
//features. Takes in d of type struct House and
//returns the cost
void list_houses_with (House s[], Client_Data c, int size);
//lists the houses that meet all the requirements
//specified by the user. Takes in array of struct
//House, struct of Client_Data, and the size of
//the array

int main()
{
	House m[NUM_HOUSES];
	char ans = 'y';
	string f;
	cout << "Please provide a housing database: ";
	cin >> f;
	while ((ans == 'y') or (ans == 'Y')) 
	{
		Client_Data c;
		load_array(m, f, NUM_HOUSES);
		
		cout << "What kind of house are you looking" 
		<< " to buy or rent today?" << endl;
		cout << "Number of bedrooms?" << endl;
		cin >> c.bed_des;
		cout << "Number of baths?" << endl;
		cin >> c.bath_des;
		cout << "Number of floors?" << endl;
		cin >> c.floor_des;
		list_houses_with (m, c, NUM_HOUSES);

		cout << "Want to continue?" << endl;
		cin >> ans;
	}
	return 0;
}


// Function definitions
void print_house (House h)
{
	cout << "\n";
	cout <<"House at " << h.address
	<< ": " << endl;
	cout << h.bed << " beds, "<< h.bath 
	<< " baths, " << h.floor << " floors" << endl;
	
	if (h.occup == false)
		cout << "Not occupied! For sale." << endl;
	else
		cout << "Occupied. Not for sale." << endl;

	cout << "Cost to buy: " 
	<< calculate_cost(h) << endl;
	cout << "Cost to rent: " 
	<< calculate_rental_cost(h) << " per month." 
	<< endl;
	cout << "\n";
}

void load_array (House m[], string f, int size)
{
	char k;
	ifstream inFile;
	inFile.open(f.c_str());
	for (int i = 0; i < size; i++){
		inFile >> m[i].bed;
		inFile >> m[i].bath;
		inFile >> m[i].floor;
		inFile >> m[i].address;
		inFile >> k;
		k = tolower(k , locale());
		if (k == 't')
			m[i].occup = true;
		else
			m[i].occup = false;

	}
}

int calculate_cost (House g)
{
	int bed_cost = 100000 * g.bed;
	float bath_cost = 20000 * g.bath;
	int floor_cost = 30000 * g.floor;
	float tot_cost = bed_cost + bath_cost - floor_cost;

	if (tot_cost < 150000)
		tot_cost = 150000;
	if (tot_cost > 1000000)
		tot_cost = 1000000;
	
	return tot_cost;
}

float calculate_rental_cost (House d)
{
	return 500 * d.bed + 200 * d.bath + 100 * d.floor;
}

void list_houses_with (House s[], Client_Data c, int size)
{
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (((s[i].bed == c.bed_des) or 
			(c.bed_des == -1)) and 
			((s[i].bath == c.bath_des) or 
				(c.bath_des == -1)) and 
			((s[i].floor == c.floor_des) or 
				(c.floor_des == -1))) 
		{
			print_house(s[i]);

			k++;
		}
	}
	if (k == 0)
		cout << "No matching houses found!" << endl;
}