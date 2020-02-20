
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct House {
    int bed;
    float bath;
    int floor;
    string address;
    bool occup;
};
const int NUM_HOUSES = 10;

void print_house (House h);
int calculate_cost(House g);
float calculate_rental_cost(House d);
void load_array(House m[], string filename);


int main()
{
	House h;
	h.bed = 5;
	h.bath = 2.5;
	h.floor = 3;
	h.address = "middle of fackin nowhere";
	h.occup = false;

	print_house(h);

	House m[NUM_HOUSES];
	load_array(m, "houses.db");

	return 0;
}

void print_house (House h)
{
	cout << h.bed << endl;
	cout << h.bath << endl;
	cout << h.floor << endl;
	cout << h.address << endl;
	cout << h.occup << endl;
	cout << calculate_cost(h) << endl;
	cout << calculate_rental_cost(h) << endl;
}

int calculate_cost(House g)
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

float calculate_rental_cost(House d)
{
	return 500 * d.bed + 200 * d.bath + 100 * d.floor;
}

void load_array(House m[], string filename)
{
	char k;
	ifstream inFile;
	inFile.open(filename.c_str());
	for(int i = 0; i < NUM_HOUSES; i++){
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
	for(int i = 0; i < NUM_HOUSES; i++){
		cout << m[i].bed << endl;
		cout << m[i].bath << endl;
		cout << m[i].floor << endl;
		cout << m[i].address << endl;
		cout << m[i].occup << endl;
	}
	inFile.close();
}
