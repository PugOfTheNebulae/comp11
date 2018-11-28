// Alyssa Rose

// Alyssa Rose

#include <string>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <iostream>

#include "game.h"
#include "int-string.h"
using namespace std;

string const UP = "w";
string const DOWN = "s";
string const LEFT = "a";
string const RIGHT = "d";
string const DISP5 = "h";
string const QUIT = "q";
string const BLNK = "-";

string const CLR = "clear";
string const SHOW = "show";
string const KEEP = "keep";

Game::Game(){
	cerr << __func__ << " " << __LINE__ << endl;
	cout << "Enter desired dimension of board: ";
	cin >> dim;
	Row = 1;
	Col = dim;

	string **board = new string*[Row];
	for (int i = 0; i < Row; i++)
		board[i] = new string[dim];

	//highScores;
	score = 0;
}

void Game::print_number(string num) {
    printf("%-6s", num.c_str());
}

void Game::play(){
	if (dim < 2){
		cerr << "Wrong Dimensions";
		exit(1);
	}
	//prt_start();
	prt_brd();

	while (filled() and make_mv()){
		string in, in2;
		cin >> in;
		cin >> in2;
		if (in == LEFT){
			left_push();
			merge_left();
			left_push();
		}
		else { //if (in == RIGHT)
			right_push();
			merge_right();
			right_push();
		}
		//else if (in == UP)
			//move_up();
		//else if (in == DOWN)
			//move_down();
		//else
			//play_other(in, in2);
	}
	//end_game();
}

Game::~Game(){
	for (int i = 0; i < Row; i++)
		delete [] board[i];
	delete [] board;

}

/*
* generates either 2 or 4
*/
string Game::rando_num(){
	srand(time(0));
	double prob = (rand() % 10) + 1;
	if (prob <= 9)
		return "2";
	else
		return "4";
}

void Game::rando_loc(){
	int col, row;
	srand(time(0));
	row = rand() % dim;
	col = rand() % dim;
	while (board[Row - 1][col] != BLNK){
		//row = rand() % dim;
		col = rand() % dim;
	}
	board[Row - 1][col] = rando_num();
}
/*
* makes initial board
*/
void Game::new_brd()
{
	srand(time(0));
	for (int i = 0; i < Row; i++){
		for(int j = 0; j < Col; j++)
			board[i][j] = BLNK;
	}
	int cnt = 0;
	while (cnt < 2) {
		int j = (rand() % dim);
		//int i = (int)round((rand() % dim));
		if (board[Row - 1][j] == BLNK){
			board[Row - 1][j] = rando_num();
			cnt++;
		}
	}
}
//********************************************************************************
/*
* prints starting message
*/
// void Game::prt_start(){
// 	cout << "Starting game! High score is "
// 	<< highScores.highestScore(); << endl;
// }

/*
* prints the current board
*/
void Game::prt_brd(){
	//cout << "Current score: " << score << endl;
	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Col; j++)
			print_number(board[i][j]);
}

/*
* checks if the board is full
*/
bool Game::filled(){
	for (int i = 0; i < Row; i++){
		for (int j = 0; j < Col; j++){
			if (board[i][j] == BLNK)
				return 1;
		}
	}
	return 0;

}

/*
* checks if user can make a move
*/
bool Game::make_mv(){
	for (int i = 0; i < Row; i++){
		for (int j = 0; j < Col - 1; j++){
			if (//(board[i+1][j] == board[i][j]) or
				//(board[i-1][j] == board[i][j]) or
				(board[i][j+1] == board[i][j]))
				return 1;
		}
	}
	return 0;
}

// void Game::end_game(){
// 	string name;
// 	cout << "Game over! Enter your name to record your score: ";
// 	cin >> name;
// 	highScores.insert(name, score);
// }

// void Game::play_other (string in, string in2){
// 	if (in == DISP5)
// 		highScores.printTop5();
// 	if else (in == SHOW)
// 		highScores.print_user(in2);
// 	if else(in == QUIT)
// 		end_game(score);
// 	if else(in == CLR)
// 		highScores.clear();
// 	if else(in == KEEP)
// 		highScores.keepTopTen();
// 	else
// 		cout << "Command not recognized. Please try again.\n"
// }
/***********************************************************************************************************************/
/*
* function to push everything left
* if left arrow pushed
*/
void Game::left_push(){
	int col_nxt;
	for (int i = 0; i < Row; i++){
		for (int j = 0; j < Col; j++){
			if (board[i][j] == BLNK){
				for (col_nxt = j++; col_nxt < dim; col_nxt++){
					if (board[i][col_nxt] != BLNK){
						board[i][j] = board[i][col_nxt];
						board[i][col_nxt] = BLNK;
					}
					//break;
				}
			}

		}
	}

}

/*
* function to push everything right
* if right arrow pushed
*/
void Game::right_push(){
	int col_nxt;
	for (int i = 0; i < Row; i++){
		for (int j = Col - 1; j > 0; j--){
			if (board[i][j] == BLNK){
				for (col_nxt = j--; col_nxt > 0; col_nxt--){
					if (board[i][col_nxt] != BLNK){
						board[i][j] = board[i][col_nxt];
						board[i][col_nxt] = BLNK;
					}
					//break;
				}
			}
		}
	}
}
/*
* pushes all pieces down
*/
// void Game::down_push(){
// 	int row_nxt;
// 	for (int i = dim - 1; i > 0; i--){
// 		for (int j = 0; j < dim; j++){
// 			if (board[i][j] == BLNK){
// 				for (row_nxt = i--; row_nxt > 0; row_nxt--){
// 					if (board[row_nxt][j] != BLNK){
// 						board[i][j] = board[row_nxt][j];
// 						board[row_nxt][j] = BLNK:
// 					}
// 					//break;
// 				}
// 			}
// 		}
// 	}
// }


// * pushes all pieces up

// void Game::up_push(){
// 	int row_nxt;
// 	for (int i = 0; i < dim; i++){
// 		for (int j = 0; j < dim; j++){
// 			if (board[i][j] = BLNK){
// 				for (row_nxt = i++; row_nxt < dim; row_nxt++){
// 					if(board[row_nxt][j] != BLNK){
// 						board[i][j] = board[row_nxt][j];
// 						board[row_nxt][j] = BLNK;
// 					}
// 					//break;
// 				}
// 			}
// 		}
// 	}
// }
/*********************************************************************************************************************/
void Game::merge_left(){
	int col_nxt;
	for (int i = 0; i < Row; i++){
		for (int j = 0; j < Col; j++){
			if (board[i][j] != BLNK){
				for (col_nxt = j++; col_nxt < dim; col_nxt++){
					if (board[i][col_nxt] != BLNK){
						if (board[i][col_nxt] == board[i][j]){
							score += string2int(board[i][j]) * 2;
							board[i][j] = int2string(string2int(board[i][j]) * 2);
							board[i][col_nxt] = BLNK;
						}
					}
				}
			}
		}
	}
}

void Game::merge_right(){
	int col_nxt;
	for(int i = 0; i < Row; i++){
		for (int j = Col - 1; j > 0; j--){
			if (board[i][j] != BLNK){
				for (col_nxt = j--; col_nxt > 0; col_nxt--){
					if (board[i][col_nxt] == board[i][j]){
						score += string2int(board[i][j]) * 2;
						board[i][j] = int2string(string2int(board[i][j]) * 2);
						board[i][col_nxt] = BLNK;
					}
				}
			}
		}
	}
}

// void Game::merge_down(){
// 	int row_nxt;
// 	for (int i = dim; i > 0; i--){
// 		for (int j = 0; j < dim; j++){
// 			if (board[i][j] == BLNK){
// 				for (row_nxt = i--; row_nxt > 0; row_nxt--){
// 					if (board[row_nxt][j] == board[i][j]){
// 						board[i][j] = int2string(string2int(board[i][j]) * 2);
// 						board[row_nxt][j] = BLNK;
// 					}
// 					break;
// 				}
// 			}
// 		}
// 	}
// }

// void Game::merge_up(){
// 	int row_nxt;
// 	for (int i = 0; i < dim; i++){
// 		for (int j = 0; j < dim; j++){
// 			if (board[i][j] = BLNK){
// 				for (row_nxt = i++; row_nxt < dim; row_nxt++){
// 					if(board[row_nxt][j] == board[i][j] ){
// 						board[i][j] = int2string(string2int(board[i][j]) * 2);
// 						board[row_nxt][j] = BLNK;
// 					}
// 					break;
// 				}
// 			}
// 		}
// 	}

// }
