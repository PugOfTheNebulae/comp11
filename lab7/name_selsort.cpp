#include <iostream>

using namespace std;

/*
 * nam_selsort.cpp - selection sort (with count of swaps and compares)
 *
 * purpose:     see how count of swaps and comps depends on
 *              a) order of input data
 *              b) size of data set
 *
 * modified by:  alyssa rose
 * on date:      23-10-2018
 */

const int SIZE = 50000;

struct Person {
        int     year;
        string  name;
};

int read_in_data(Person list[], int space);
void name_sort(Person list[], int len);
void print_list(Person list[], int len);
int index_of_lowest(Person list[],int start, int last);
void swap_elements(Person list[],int pos1, int pos2);

int main()
{
        Person  list[SIZE];
        int     len = 0;

        len = read_in_data(list, SIZE);
        name_sort(list, len);
        print_list(list, len);
        return 0;
}

/*
 * read_in_data --- read in list of year, name from cin
 * args: list to read, maxlen
 * rets: number of items read
 * note: truncates input if space is filled, no error report
 * NEW!: stops at EOF, no sentinel needed
 */
int read_in_data(Person list[SIZE], int space)
{
        int     pos = 0;

        while (pos < space) {
                cin >> list[pos].year;
                if (cin.eof())
                        break;
                cin >> list[pos].name;
                pos++;
        }
        return pos;
}

/*
 * name_sort -- sort an array structs on name
 *   args: array of structs, number of elements in array
 *   rets: nothing
 *   acts: a) Sorts the array using the selection sort algorithm
 *         b) At end, prints number of comparisons and number of swaps
 */
void name_sort(Person list[SIZE], int len)
{
  int i = 0;
  while (i < (len - 1)){
    int last = len - 1;
    //length will change every iteration
    int start = i;
    swap_elements(list, start, index_of_lowest(list, start, last));
    i++;
    
  }
}

// -------------------- WRITE TWO HELPER FUNCTIONS -----------------

// int index_of_lowest(int list[], int start, int last)
//   args: array of structs, start of range, end of range
//   rets: index of lowest item in range
//   note: if two with lowest, returns first one
int index_of_lowest(Person list[], int start, int last){
  int min = list[start].year;
  int index = 0;
  for (int i = start; i < (last); i++){
    if (list[i].year < min){
      min = list[i].year;
      index = i;
    }
  }
  return index;
}
		

// void swap_elements(int list[], int pos1, int pos2)
//   args: array of structs, index of pos1, index of pos2
//   rets: nothing
void swap_elements(Person list[], int pos1, int pos2){
  int temp = list[pos1].year;
  list[pos1].year = list[pos2].year;
  list[pos2].year = temp;
}

// -------------------- END OF HELPER FUNCTIONS --------------------

/*
 * print_list -- print the list to cout
 *  args: array of strings, number of elements to print
 *  rets: nothing
 *  acts: loops through array sending each item to cout
 */
void print_list(Person list[SIZE], int len)
{
        int i;
        for (i = 0; i < len; i++) {
                cout << list[i].year << " " 
                     << list[i].name << endl;
        }
}
