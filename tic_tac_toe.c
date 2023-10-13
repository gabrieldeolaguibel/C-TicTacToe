# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
// This will have the implementations for displayGrid, checkWin, isValidMove, isDraw, and any other helper functions we need.


// intialize the board (3x3 grid)
char board[3][3];

//initialize the board with empty spaces to start
void initializeBoard() { // no board is passed in because we are using the global board
    for (int i = 0; i < 3; i++ ){
        for (int j = 0; i < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// display the board
void displayBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; i < 3; j++) {
            printf("%c", board[i][j]); // print the board 
            if (j != 2){ // if we are not at the end of the row
                printf("|"); // print the vertical lines
            }
        }
        printf("\n"); // print the horizontal lines
        if (i != 2) { // if we are not at the end of the column
            printf("---------\n"); // print the horizontal lines
        }
    }
}

// check if the move is valid
bool isValidMove(int row, int column) {
    return (
            row >= 0 // if the row is greater than or equal to 0 and 
            && row < 3 // less than 3 and
            && column >= 0 // the column is greater than or equal to 0 and
            && column < 3 // less than 3 and
            && board[row][column] == ' '); // the board at the row and column is empty
            // if all these conditions are true, then the move is valid becuase it is within the bounds of the board and the space is empty
}

// Check if someone has won
bool checkWin(char player) {
    // check the rows and columns
    for (int i = 0; i < 3; i++) {
        // check the rows
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) { // check the rows
            return true;
        }
        // check the columns
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) { // check the columns
            return true;
        }
    }
    // check the positive slope diagonal
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    // check the negative slope diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false; // no win
}

// check if the game is a draw
bool isDraw() {
    // check if the board is full
    for (int i = 0; i < 3; i++){
        for (int j = 0; i < 3; j++){
            if (board[i][j] == ' ') { // if there is an empty space
                return false; // the game is not a draw
            }
        }
    }
    return true; // the game is a draw
}