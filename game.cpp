// Alyssa Rose

#include <string>
#include <cstdio>

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

highScoresList highScores;
Game::Game(){
	int dim;
	cout << "Enter desired dimension of board: ";
	cin >> dim;
}

void Game::print_number(string num) {
    printf("%-6s", num.c_str());
}

void Game::play(){
	if (dim < 2){
		cerr << "Wrong Dimensions";
		exit(1);
	}
	int score = 0;
	string *board = new_brd(dim);
	prt_start();
	prt_brd(board, dim);

	while (filled(board, dim) and make_mv(board, dim)){
		string in, in2;
		// need to rethink for show
		cin >> in;
		cin >> in2;
		if (in == UP)
			move_up(board);
		else if (in == DOWN)
			move_down(board);
		else if (in == LEFT)
			move_left(board);
		else if (in == RIGHT)
			move_right(board);

		else
			play_other(in, in2, score);
	}
	end_game(score);
}

Game::~Game(){
	delete board;
}

/*
* generates either 2 or 4
*/
int Game::rando(){
	double prob1 = (rand() % 10);
	if (prob <= 9)
		return 2;
	else
		return 4;
}


/*
* makes initial board
*/
string *Game::new_brd(dim){
	string *board = new string[1][dim];
	for (int i = 0; i < dim; i++){
		board[1][i] = BLNK;
	}
	for (int i = 0; i < 2; i++){
		int j = (int)round((rand() % dim));
		while(board[i][j] == BLNK)
			j = (int)round((rand() % dim));
		board[1][j] = rando();
	}
	return board;
}

/*
* prints starting message
*/
void Game::prt_start(){
	cout << "Starting game! High score is "
	<< highScores.highestScore(); << endl;

}

/*
* prints the current board
*/
void Game::prt_brd(string *board, int dim, int score){
	cout << "Current score: " << score << endl;
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			print_number((board[i][j]))
		}
	}

}

/*
* checks if the board is full
*/
bool Game::filled(string *board, int dim){
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			if (board[i][j] = BLNK)
				return 1;
		}
	}
	return 0;

}

/*
* checks if user can make a move
*/
bool Game::make_mv(string *board, int dim){
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			if ((board[i+1][j] == board[i][j]) or
				(board[i-1][j] == board[i][j]) or
				(board[i][j+1] == board[i][j]) or
				(board[i][j-1] == board[i][j]))
				return 1
			else
				return 0;
		}
	}
}

void Game::end_game(){
	string name;
	cout << "Game over! Enter your name to record your score: ";
	cin >> name;
	highScores.insert(name, score);
}

void Game::play_other (string in, string in2, int score){
	if (in == DISP5)
		highScores.printTop5();
	if (in == SHOW)
		highScores.print_user(in2);
	if (in == QUIT)
		end_game(score);
	if (in == CLR)
		highScores.clear();
	if (in == KEEP)
		highScores.keepTopTen();
	else
		cout << "Command not recognized. Please try again.\n"
}

/*
* function to push everything left
* if left arrow pushed
*/
void Game::left_push(string *board, int dim){
	int col_nxt;
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			if (board[i][j] == "-"){
				for (col_nxt = j++; col_nxt < dim; col_nxt++){
					if (board[i][col_nxt] != "-"){
						board[i][j] = board[i][col_nxt];
						board[i][col_nxt] = "-";
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
void Game::right_push(string *board, int dim){
	int col_nxt;
	for (int i = 0; i < dim; i++){
		for (int j = dim; j > 0; j--){
			if (board[i][j] == "-"){
				for (col_nxt = j--; col_nxt > 0; col_nxt--){
					if (board[i][col_nxt] != "-"){
						board[i][j] = board[i][col_nxt];
						board[i][col_nxt] = "-";
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
void Game::down_push(string *board, int dim){
	int row_nxt;
	for (int i = dim; i > 0; i--){
		for (int j = 0; j < dim; j++){
			if (board[i][j] == "-"){
				for (row_nxt = i--; row_nxt > 0; row_nxt--){
					if (board[row_nxt][j] != "-"){
						board[i][j] = board[row_nxt][j];
						board[row_nxt][j] = "-":
					}
					//break;
				}
			}
		}
	}
}

/*
* pushes all pieces up
*/
void Game::up_push(string *board, int dim){
	int row_nxt;
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			if (board[i][j] = "-"){
				for (row_nxt = i++; row_nxt < dim; row_nxt++){
					if(board[row_nxt][j] != "-"){
						board[i][j] = board[row_nxt][j];
						board[row_nxt][j] = "-";
					}
					//break;
				}
			}
		}
	}
}

void Game::merge_left(string *board, int dim){
	int col_nxt;
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			if (board[i][j] != "-"){
				for (col_nxt = j++; col_nxt < dim; col_nxt++){
					if (board[i][col_nxt] != "-"){
						if (board[i][col_nxt] == board[i][j]){
							board[i][j] = int2string(string2int(board[i][j]) * 2);
							board[i][col_nxt] = "-";
						}
						break;
					}
				}
			}
		}
	}
}

void Game::merge_right(string *board, int dim){
	int col_nxt;
	for(int i = 0; i < dim; i++){
		for (int j = dim; j > 0; j--){
			if(board[i][j] != "-"){
				for (col_nxt = j--; col_nxt > 0; col_nxt--){
					if (board[i][col_nxt] == board[i][j]){
						board[i][j] = int2string(string2int(board[i][j]) * 2);
						board[i][col_nxt] = "-"
					}
					break;
				}
			}
		}
	}
}

void Game::merge_down(string *board, int dim){
	int row_nxt;
	for (int i = dim; i > 0; i--){
		for (int j = 0; j < dim; j++){
			if (board[i][j] == "-"){
				for (row_nxt = i--; row_nxt > 0; row_nxt--){
					if (board[row_nxt][j] == board[i][j]){
						board[i][j] = int2string(string2int(board[i][j]) * 2);
						board[row_nxt][j] = "-":
					}
					break;
				}
			}
		}
	}
}

void Game::merge_up(string *board, int dim){
	int row_nxt;
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			if (board[i][j] = "-"){
				for (row_nxt = i++; row_nxt < dim; row_nxt++){
					if(board[row_nxt][j] == board[i][j] ){
						board[i][j] = int2string(string2int(board[i][j]) * 2);
						board[row_nxt][j] = "-";
					}
					break;
				}
			}
		}
	}

}
