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
that do very basic task (like print board), which
was used in conjuction with all of my functions
that created different boards necessary to my program.
*/

//instance of data structure (type 2D array)
void print_board (char board[SIZE][SIZE]);
void first_board (char board[SIZE][SIZE]);
int hid_board (char board[SIZE][SIZE]);
int you_lost(char board[SIZE][SIZE]);
int you_won(char board[SIZE][SIZE]);
int num_mines (int row, int col, char board[SIZE][SIZE]);
bool wrong_dim(int row, int col);
bool choose_again (int row, int col, char board[SIZE][SIZE]);

int main(){
    char board_print[SIZE][SIZE], board_actual[SIZE][SIZE];
    first_board(board_print);
    print_board(board_print);
    int num_x = hid_board(board_actual), outcome = 0, mine, pick = 0;
    while (outcome == 0){
        int row, col;
        cout << "Enter the row and column of the square to uncover: ";
        cin >> row;
        cin >> col;
        //checks if input valid in 2 ways
        bool choose = choose_again (row, col, board_print);
        bool dim = wrong_dim (row, col);
        if (board_actual[row][col] == MINE)
            outcome = you_lost(board_actual);
        else {
            mine = num_mines(row, col, board_actual);
            board_print[row][col] = mine + '0';
            print_board(board_print);
            if ((!dim) and choose)
                pick++;
            if (pick == ((SIZE*SIZE) - (num_x)))
                outcome = you_won(board_print);
        }
    }
    return 0;
}


//int hid_board (char board[SIZE][SIZE]);
//Purpose: creates the "hidden" board that the user
//          is using to play against
//Parameters: board[SIZE][SIZE] of type char
//Returns: number of mines in board (integer)
//Notes: return value is used to determine when
//       user has won
int hid_board (char board[SIZE][SIZE]){
    int tries = 0; 
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            double prob = (rand() % 10) / 10.0;
            if (prob <= 0.3){
                board[i][j] = MINE;
                tries++;
            }
            else
                board[i][j] = UNSEEN;
        }
    }
    return tries;
}


//void first_board (char board[SIZE][SIZE]);
//Purpose: creates the first board printed to screen
//Parameters: board[SIZE][SIZE] of type char
//Returns: None
//Effects: None
//Notes: used with print_board to print to
//       standard output
void first_board (char board[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            board[i][j] = UNSEEN;
        }
    }
}


//void print_board (char board[SIZE][SIZE]);
//Purpose: prints out a 2d array (board) to screen
//Parameters: board[SIZE][SIZE] of type char
//Returns: None
//Effects: prints to standard output
//Notes: None
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


//int you_lost(char board[SIZE][SIZE]);
//Purpose: prints out board with mines and 
//          the phrase "GAME OVER. YOU LOST!"
//Returns: the integer 1 (outcome)
//Effects: results in while loop in main ending
//Notes: only called when board[row][col] contains
//       MINE, used in conjuction with print_board
int you_lost(char board[SIZE][SIZE])
{
    print_board(board);
    cout << "GAME OVER. YOU LOST!\n";
    return 1;
}


//int you_won(char board[SIZE][SIZE]);
//Purpose: prints out board with num mines in 
//vicinity and phrase "GAME OVER. YOU WON!"
//Returns: the integer 1 (outcome)
//Effects: results in while loop in main ending
//Notes: only called when all non MINE spaces
//       have been chosen, used in conjuction
//       with print_board
int you_won(char board[SIZE][SIZE])
{
    print_board(board);
    cout << "GAME OVER. YOU WON!\n";
    return 1;
}


//bool wrong_dim(int row, int col);
//Purpose: prints out error message if the dimensions
//         entered are not 0 to 8 
//Returns: false if the dimensions are out of bounds
//Effects: prints message to std output
//Notes: None
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


//bool choose_again (int row, int col, char board[SIZE][SIZE]);
//Purpose: checks if user already selected the square
//Parameters: row and col numbers played, board[SIZE][SIZE] 
//            of type char
//Returns: false if already chosen, true if not
//Effects: prints message asking user to choose again
//Notes: None
bool choose_again (int row, int col, char board[SIZE][SIZE])
{
    if((row < 9) and (row >= 0) and (col >= 0) and (col < 9)){
        if (board[row][col] != UNSEEN){
            cout << "Bad input. Select another square." << endl;
            return false;
        }
        else {
            return true;
        }
    }

    else {
        return true;
    }
}


//int num_mines (int row, int col, char board[SIZE][SIZE]);
//Purpose: counts the number of mines in the vicinity
//Parameter: row and col numbers played, board[SIZE][SIZE] 
//       of type char
//Returns: number of mines in the vicinity
//Effects: None
//Notes: used in conjuction with print_board
int num_mines (int row, int col, char board[SIZE][SIZE])
{
    //adapts edge cases to work within function by
    //forcing row/col fwd and back to be max 8 and
    //min 0 respectively
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
