#include <iostream>
#include <time.h> 
#include <cstdlib>
#include <string>

using namespace std;

const int SIZE = 10;


void print_board (char board[SIZE][SIZE]);
void first_board (char board[SIZE][SIZE]);
int hid_board (char board[SIZE][SIZE]);
int num_mines (int row, int col, char board[SIZE][SIZE]);

int main(){

	char board_print[SIZE][SIZE];
	char board_actual[SIZE][SIZE];

	first_board(board_print);
	print_board(board_print);
	int num_x = hid_board(board_actual);
	print_board(board_actual);

	int outcome = 0, mine, tries = 0;
	while (outcome == 0){
		int row, col;
		cout << "Enter the row and column of the square to uncover: ";
		cin >> row;
		cin >> col;

		if (board_actual[row][col] == 'x'){
			outcome = 1;
			print_board(board_actual);
			cout << "GAME OVER. YOU LOST!" << endl;
		}

		else {
			mine = num_mines(row, col, board_actual);
			mine += '0';
			board_print[row][col] = mine;
			print_board(board_print);
			tries++;
			if (tries == num_x){
				print_board(board_print);
				cout << "GAME OVER. YOU WON!" << endl;
				outcome = 1;
			}

		}
	}
	return 0;
}

int hid_board (char board[SIZE][SIZE]){
	srand(time(NULL));
	int tries = 0; 
	for (int i = 0; i < (SIZE - 1); i++){
		for (int j = 0; j < (SIZE - 1); j++){
			bool prob = rand() % 10 < 3;
			if (prob){
				board[i][j] = 'x';
				tries++;
			}
			else
				board[i][j] = '-';

		}
	}
	return tries;
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

	for (int i = row_bk; i <= row_fwd; i++){
		for (int j = col_bk; j <= col_fwd; j++){
			if (board[i][j] == 'x')
				cnt++;
		}
	}
	return cnt;
}
