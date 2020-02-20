/*
 * printlist.cpp  -- shows how to read a list of numbers into an array
 *
 *      1. read in data
 *      2. then prints out the list with line numbers using another loop
 *
 *   TODO:
 *    [a] change loop to print out only the birthdays in October
 *    [b] after printing out the October bdays, print a count of how many
 *    [c] change to print the count for each month, not the actual bdays
 *    [d] use a function to do [c]
 *    [e] EXTRA: print which month has the MOST birthdays
 */
#include <iostream>

using namespace std;

const int CAPACITY = 1000;         // change as needed
int count_bd(int m, int bdays[]);

int main() 
{
        int bdays[CAPACITY];    // birthday data
        int used;               // number of spaces used so far
        int pos;                // position in array

        // read in CAPACITY values
        pos = 0;
        while (pos < CAPACITY) {
                cin >> bdays[pos];
                pos++;
        }
        used = pos;             // position is how far we got

        // now to print out the list, use a for loop for a change
	int m = 1;
	while(m < 13){
	  count_bd(m, bdays);
	  m++; 
	}
        return 0;
}

int count_bd(int m, int bdays[]){
  m = m*100;
  int i = 0;
  for (int pos = 0; pos < CAPACITY; pos = pos+1) {
    if ((bdays[pos] >= m) and (bdays[pos] < (m + 100))){
      i++;
    }
  }
  cout << i << endl;
  return i;
}
  
  
