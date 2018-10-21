#include <iostream>
#include <time.h> 
#include <cstdlib>
#include <string>

using namespace std;

const int SIZE = 10;


void print_board (char board[SIZE][SIZE]);
void first_board (char board[SIZE][SIZE]);
void hid_board (char board[SIZE][SIZE]);
int num_mines (int row, int col, char board);

int main(){

	char board_print[SIZE][SIZE];
	char board_actual[SIZE][SIZE];
	first_board(board_print);
	print_board(board_print);
	hid_board(board_actual);
	print_board(board_actual);

	int outcome = 0, mine;
	while (outcome == 0){
		int row, col;
		cout << "Enter the row and column of the square to uncover: ";
		cin >> row;
		cin >> col;

		if (board_actual[row][col] == 'x'){
			outcome = 1;
			for (int i = 0; i < (SIZE - 1); i++){
				for (int j = 0; j < (SIZE - 1); j++){
					if (board_actual[i][j] == 'x')
						board_print[i][j] = 'x';
				}
			}
			print_board(board_print);
			cout << "GAME OVER. YOU LOST!" << endl;
		}

		else {
			mine = num_mines(row, col, board_actual);
			board_print[row][col] = mine + '\0';
			print_board(board_print);
		}
	}

	return 0;
}

void hid_board (char board[SIZE][SIZE]){
	srand(time(NULL)); 
	for (int i = 0; i < (SIZE - 1); i++){
		for (int j = 0; j < (SIZE - 1); j++){
			bool prob = rand() % 10 < 3;
			if (prob)
				board[i][j] = 'x';
			else
				board[i][j] = 'o';

		}
	}
}

void first_board (char board[SIZE][SIZE]){
	for (int i = 0; i < (SIZE - 1) ; i++){
		for (int j = 0; j < (SIZE - 1); j++){
			board[i][j] = '-';
		}
	}
}

void print_board (char board[SIZE][SIZE]){
	cout << "  0 1 2 3 4 5 6 7 8 \n";
	for (int i = 0; i < (SIZE - 1); i++){
		string m = " ";
		for (int j = 0; j < (SIZE - 1); j++){
			m = m + board[i][j] + " ";
		}
		cout << i << m << endl;
		
	}
}

int num_mines (int row, int col, char board[SIZE][SIZE])
{
	//check if 'x' in vicinity
	int row_bk = row - 1;
	int row_fwd = row + 1;
	int col_bk = col - 1;
	int col_fwd = col + 1;
	int cnt = 0;

	for (int i = row_bk; i < row_fwd; i++){
		for (int j = col_bk; j < col_fwd; j++){
			if (board[row][col] == 'x')
				cnt++;
		}
	}
}
