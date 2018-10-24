/* 
 * minesweeper.cpp 
 *
 * A text-based minesweeper game that runs in the terminal.
 *
 * COMP11 Fall 2018
 * Modified by: Alyssa Rose
 * Date: 19-October-2018
 */

#include <iostream>
#include <time.h> 
#include <cstdlib>
#include <string>

using namespace std;

/* Set random seed */
#ifdef TESTING
#define RANDOMSEED 1
#else
#define RANDOMSEED time(NULL)
#endif

char const UNSEEN = '-';
char const MINE = 'x';
int const SIZE = 9;

/*
Notes : Deciding on the type of data sctructure
to use was the most challenging part, but I decided
to go with a 2D array. Incorporting my functions
into an overall program was much easier using a 2D
array instead of structs which led to my decision.
I stitched together my functions by having ones
that do very basic task (like print board), whcih
was used in conjuction with all of my functions
that created different boards necessary to my program.
*/

void print_board (char board[SIZE][SIZE]);
//prints out a 2d array (board) to screen
//input: board[SIZE][SIZE] of type char
void first_board (char board[SIZE][SIZE]);
//creates the first board printed to screen
//input: board[SIZE][SIZE] of type char
int hid_board (char board[SIZE][SIZE]);
//creates the "hidden" board that the user
//is using to play
//input: board[SIZE][SIZE] of type char
//output: number of mines in board (integer)
int you_lost(char board[SIZE][SIZE]);
//prints out board with mines and the phrase you lost
//and returns the value 1 (outcome) which tells
//the loop that it can end
int you_won(char board[SIZE][SIZE]);
//prints out board with num mines in vicinity and 
//mphrase you won and returns the value 1 (outcome)
// which tells the loop that it can end
int num_mines (int row, int col, char board[SIZE][SIZE]);
//counts the number of mines in the vicinity
//input: row and col numbers played, board[SIZE][SIZE] 
//		 of type char
//output: number of mines in the vicinity
bool wrong_dim(int row, int col);
//prints out error message if the dimensions
//entered are not 0 to 8 and returns false if
//the dimensions are out of bounds
void choose_again (int row, int col, char board[SIZE][SIZE]);
//checks if user already selected the square and
//returns error message if they have
int main(){
	//instance of data structure (type array)
	char board_print[SIZE][SIZE];
	char board_actual[SIZE][SIZE];
	first_board(board_print);
	print_board(board_print);
	int num_x = hid_board(board_actual);
	int outcome = 0, mine, tries = 0;

	while (outcome == 0){
		int row, col;
		cout << "Enter the row and column of the square to uncover: ";
		cin >> row;
		cin >> col;
		choose_again (row, col, board_print);
		wrong_dim (row, col);
		if (board_actual[row][col] == MINE){
			outcome = you_lost(board_actual);
		}

		else {
			mine = num_mines(row, col, board_actual);
			mine += '0';
			board_print[row][col] = mine;
			print_board(board_print);
			tries++;
			if (tries == ((SIZE*SIZE) - num_x)){
				outcome = you_won(board_print);
			}
		}
	}
	return 0;
}

int hid_board (char board[SIZE][SIZE]){
	srand(time(NULL));
	int tries = 0; 
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			bool prob = rand() % 10 < 3;
			if (prob){
				board[i][j] = MINE;
				tries++;
			}
			else
				board[i][j] = UNSEEN;
		}
	}
	return tries;
}


void first_board (char board[SIZE][SIZE]){
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			board[i][j] = UNSEEN;
		}
	}
}


void print_board (char board[SIZE][SIZE]){
	cout << "  0 1 2 3 4 5 6 7 8 \n";
	for (int i = 0; i < SIZE; i++){
		string m = " ";
		for (int j = 0; j < SIZE; j++){
			m = m + board[i][j] + " ";
		}
		cout << i << m << endl;
		
	}
}


int you_lost(char board[SIZE][SIZE])
{
	print_board(board);
	cout << "GAME OVER. YOU LOST!\n";
	return 1;
}


int you_won(char board[SIZE][SIZE])
{
	print_board(board);
	cout << "GAME OVER. YOU WON!\n";
	return 1;
}


bool wrong_dim (int row, int col)
{
	if ((row > 8) or (row < 0) or (col < 0) or (col > 8)){
		cout << "Bad input. Row and col must be >= 0 and < 9."
		<< endl; 
		return true;
	}
	else {
		return false;
	}
}


void choose_again (int row, int col, char board[SIZE][SIZE])
{
	if (board[row][col] != UNSEEN){
		if((row < 9) and (row >= 0) and (col >= 0) and (col < 9))
			cout << "Bad input. Select another square." << endl;
	}
}


int num_mines (int row, int col, char board[SIZE][SIZE])
{
	int row_bk = row - 1;
	if (row_bk < 0)
		row_bk = 0;

	int row_fwd = row + 1;
	if (row_fwd > 8)
		row_fwd = 8;

	int col_bk = col - 1;
	if (col_bk < 0)
		col_bk = 0;

	int col_fwd = col + 1;
	if (col_fwd > 8)
		col_fwd = 8;
	int cnt = 0;

	for (int i = row_bk; i <= row_fwd; i++){
		for (int j = col_bk; j <= col_fwd; j++){
			if (board[i][j] == MINE)
				cnt++;
		}
	}
	return cnt;
}
