#include <stdio.h>
#include <stdbool.h>
#include "tic_tac_toe.c" //import functions

// main function
int main() {
    char currentPlayer = 'X'; // initialize the current player to X since X goes first
    int row;
    int column;
    int position;

    // initialize the board
    initializeBoard();

    // Game starting messages:
    printf("Welcome to Tic Tac Toe!\n");
    printf("Enter positions as numbers from 1 to 9, as per the grid below:\n");
    printf("1 | 2 | 3\n---------\n4 | 5 | 6\n---------\n7 | 8 | 9\n"); 
    printf("Player X goes first.\n");

    // Game loop
    while (true) { // bool based on the win check and tie check
        // display the board for the player to see
        displayBoard();
        printf("Player %c, enter a position: ", currentPlayer);
        //input
        scanf("%d", &position); // using & because we are passing in the address of the variable

        // convert the given position to row and column
        row = (position - 1) / 3; 
        column = (position - 1) % 3; 

        // check if the move is valid
        if (isValidMove(row, column)) {
            board[row][column] = currentPlayer; // update the board with the current player's move
            // check if the current player has won
            if (checkWin(currentPlayer)) {
                displayBoard();
                printf("Player %c has won!\n", currentPlayer);
                break; // break out of the loop
            }
            // check if the game is a draw
            if (isDraw()) {
                displayBoard();
                printf("The game is a draw!\n");
                break; // break out of the loop
            }
            // switch the player
            if (currentPlayer == 'X') {
                currentPlayer = 'O';
            } else {
                currentPlayer = 'X';
            }
        }
        else {
            printf("Invalid move. Try again.\n");
        }

    }
    return 0;
}