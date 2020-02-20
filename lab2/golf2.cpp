/*
 * Comp 11
 * Lab 1
 * 
 * golf.cpp
 *
 * purpose: practice using booleans, conditionals, and constants
 *
 *          Program reads data about temperature, day, time, wind,
 *          whether it's raining, then prints out the price of
 *          admission to Minnie's Mini Golf for those conditions.
 *
 * modified by:  Mark A. Sheldon
 * on:           Fall 2018
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// days of the week
const int SUN = 0, MON = 1, TUE = 2, WED = 3, THR = 4, FRI = 5, SAT = 6;

// constants for rules
const double    BASE_PRICE            = 9.0;
const int       HIGH_TEMP_CUTOFF      = 80;
const int       LOW_TEMP_CUTOFF       = 65;
const double    PER_DEGREE_PENALTY    = 0.10;
const int       EVENING_START         = 17;
const double    WEEKEND_EVE_SURCHARGE = 1.00;
const double    RAIN_PENALTY          = 2.00;
const int       RAIN_YES              = 1;
const int       WIND_GRANULARITY      = 15;
const double    WIND_PENALTY          = 1.50;

int get_int(string prompt);
double f_to_c(int tempF);
bool is_expensive(double price);
int how_many_min(int hour);
string wear_sunscreen(int tempF);
int main() 
{
        // -- define vars for input and a value used in the tests below
        int     tempF, dayOweek, hour, rainP, windMPH;
        double  price;

        //
        // Avoid unused variable warnings
        //
        (void) MON; 
        (void) TUE; 
        (void) WED; 
        (void) THR; 
        (void) FRI;

        // -- set the precision 
        cout << setiosflags(ios::fixed) << setprecision(2);
        
        // -- Get data from user
        tempF = get_int("Temperature (fahrenheit)?");
        

	dayOweek = get_int("Day of week (0 = Sun, 1 = Mon, ..., 6 = Sat)?");
        
        
        hour = get_int("Hour of day (0..23)? ");
        

        rainP = get_int("Is it raining (0 = no, 1 = yes)?");
       

        windMPH = get_int("Wind speed (MPH)? ");
        

        // -- compute price based on these values

        price = BASE_PRICE;             // start here then adjust

        //
        // Adjust for temperature
        //
        if (tempF > HIGH_TEMP_CUTOFF) {
                int degrees_too_high = tempF - HIGH_TEMP_CUTOFF;
                price -= PER_DEGREE_PENALTY * degrees_too_high;
        } else if (tempF < LOW_TEMP_CUTOFF) {
                int degrees_too_low = LOW_TEMP_CUTOFF - tempF;
                price -= PER_DEGREE_PENALTY * degrees_too_low;
        }
        
        //
        // Adjust for peak time periods
        //
        if ((dayOweek == SAT) or (dayOweek == SUN) or (hour > EVENING_START))
                price += WEEKEND_EVE_SURCHARGE;
        
        //
        // Adjust for rain
        //
        if (rainP == RAIN_YES)
                price -= RAIN_PENALTY;

        //
        // Adjust for wind:  subtract for each WIND_GRANULARITY unit,
        //                   but NOT each fraction thereof.
        //                   I. e., if WIND_GRANULARITY is 15, then
        //                   20 MPH of wind only gets 1 WIND_PENALTY.
        //
        price -= (windMPH / WIND_GRANULARITY) * WIND_PENALTY;
 
        // -- report price to user

        cout << "Price: " << price << endl;
	bool expense = is_expensive(price);
	double celsius = f_to_c(tempF);
	int min = how_many_min(hour);
	string sentence = wear_sunscreen(tempF);
	
	cout << expense << endl;
	cout << celsius << endl;
	cout << min << endl;
	cout << sentence << endl;

        return 0;
}
int get_int(string prompt)
//function: get_int
//purpose: prompt user and return value
//parameters: string prompt
//returns: int value
//author: Alyssa Rose
{
  int answer;
  cout << prompt << endl;
  cin >> answer;
  return answer;
};

double f_to_c(int tempF)
//function: f_to_c
//purpose: converts fahrenheit to celsius
//parameters: int temperature in fahrenheit
//returns: double
//author: Alyssa Rose
{
  double temp = tempF;
  double celsius = (temp - 32) * (5/9);
  cout << "celsius:" << celsius  << endl;
  cout << temp << endl;
  return celsius;
};

bool is_expensive(double price)
//function : is_expensive
//purpose: determines if golfing is expensive given factors
//parameters: double price
//returns: bool
//author: Alyssa Rose
{
  bool expense;
  if (price > 9.00){
    expense = true;
  }
  else{
    expense = false;
  }
  return expense;
}

int how_many_min(int hour)
//function: how_many_min
//purpose: converts time of day in hours to minutes
//parameters: int hour
//returns: int of time converted to minutes
//author: Alyssa Rose
{
  int min;
  min = hour * 60;
  return min;
}

string wear_sunscreen(int tempF)
//function: wear_sunscreen
//purpose: tells user if sunscreen necessary
//parameters: int tempF
//returns: string telling using if they should wear sunscreem
//author: Alyssa Rose
{
  string statement;
  if (tempF > 75){
    statement = "Wear Sunscreen!";
  }
  else {
    statement = "You should still wear sunscreen!";
  }
  return statement;
}

