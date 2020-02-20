/*
 * rockdims.cpp -- analyze height and width of a digital image
 *
 *  input has "." background  and "x" for rock
 */

#include <iostream>
using namespace std;

const int WIDTH  = 200;
const int HEIGHT = 50;

const char SPACE = '.';
const char ROCK  = 'x';

// declarations go here
void read_pic(char image[HEIGHT][WIDTH]);
//reads in the file
void print_pic(char image[HEIGHT][WIDTH]);
//prints out the text file in '.' and 'x'
void get_x(char image[HEIGHT][WIDTH]);
//finds location of 'x' and calls find_w and 
//find_h to get the width and height
int find_w(int width[WIDTH]);
//finds max width
int find_h(int height[HEIGHT]);
//finds max height

// main should be very short, just an outline

int main() 
{
  char image[HEIGHT][WIDTH];
  read_pic(image);
  print_pic(image);
  get_x(image);
}

// helper functions go here
void read_pic(char image[HEIGHT][WIDTH])
{
  for(int i = 0; i < HEIGHT; i++){
    for(int j = 0; j < WIDTH; j++){
      cin >> image[i][j];
    }
  }
}

void print_pic(char image[HEIGHT][WIDTH])
{
  for(int i = 0; i < HEIGHT; i++){
    for(int j = 0; j < WIDTH; j++){
      cout << image[i][j];
    }
  }     
}

void get_x(char image[HEIGHT][WIDTH])
{
  int find_width[WIDTH];
  int find_height[HEIGHT];
  int w = 0;
  int h = 0;
  for(int i = 0; i < HEIGHT; i++)
    {
    for (int j = 0; j < WIDTH; j++)
      {
	if (image[i][j] == 'x')
	  {
	  find_width[w] = i;
	  find_height[h] = j;
	  w++; //I think segmentation error came from here(?)
	  h++;
	}
    }
    
    cout << find_h(find_height) << endl;
    cout << find_w(find_width) << endl;
  }
}
 int find_h(int height[]){
   int max =height[0];
   int min = height[0];
   for(int k = 0; k < HEIGHT; k++){
     if(height[k] < min)
       min = height[k];
     if(height[k] > max)
       max = height[k];
   }
   return max - min;
  }
 int find_w(int width[]){
   int max = width[0];
   int min = width[0];
   for(int k = 0; k < WIDTH; k++){
     if(width[k] < min)
       min = width[k];
     if(width[k] > max)
       max = width[k];
   }
   return max - min;
 }
