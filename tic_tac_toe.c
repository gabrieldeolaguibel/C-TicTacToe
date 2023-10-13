# include <stdio.h>
# include <stdlib.h>
// This will have the implementations for displayGrid, checkWin, isValidMove, isDraw, and any other helper functions we need.


// intialize the board (3x3 grid)
char board[3][3];

//initialize the board with empty spaces to start
void initializeBoard() { // no board is passed in because we are using the global board
    for (int i = 0; i < 3; i++ ){
        for (int j = 0; i < 3; j++) {
            board[i][j] = ' '
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
