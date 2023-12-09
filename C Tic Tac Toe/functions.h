#ifndef FUNCTIONS_H
#define FUNCTIONS_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <time.h>

    #define BOARD_SIDE_LENGTH 3

    char board[3][3];   // Initializes the board
    const char USER = 'X';
    const char COMPUTER = 'O';

    // Clears the board completely
    void reset() {
        
        for (int i = 0; i < BOARD_SIDE_LENGTH; i++) {
            for (int j = 0; j < BOARD_SIDE_LENGTH; j++) {
                board[i][j] = ' ';
            }
        }
    }

    void display() {    

        
        printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
    }

    int open_spaces_count() {

        // Will be 9 at the start of the program
        int open_spaces = BOARD_SIDE_LENGTH * BOARD_SIDE_LENGTH;

        // Subtracts 1 from open spaces if a spot is not empty
        for (int i = 0; i < BOARD_SIDE_LENGTH; i++) {
            for (int j = 0; j < BOARD_SIDE_LENGTH; j++) {
                if (board[i][j] != ' ') {
                    open_spaces--;
                }
            }
        }
        return open_spaces;
    }

    void user_turn() {

        int row, column;

        do {
        printf("Row selection (1-3): ");
        scanf("%d", &row);
        row--;  // Because the selection will be
                // off by 1 when used as an index

        printf("\nColumn selection (1-3): ");
        scanf("%d", &column);
        column--; 
        printf("\n");

        if (board[row][column] != ' ') {
            printf("This slot is occupied\n");
        }
        else {
            board[row][column] == USER;
            break;
        }
        } while (board[row][column] != ' ');
    }

    void computer_move() {
        
    }
    
    char determine_winner() {

        // Checking if there is a horizontal win in any row
        for (int i = 0; i < BOARD_SIDE_LENGTH; i++) {

            if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
                return board[i][0]; // Returns the row that won
            }
        }

        /// Checking if there is a vertical win in any column
        for (int i = 0; i < BOARD_SIDE_LENGTH; i++) {

            if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
                return board[0][i]; // Returns the column that won
            }
        }

        // Checking diagonals
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            return board[0][0];
        }
        if (board[0][2] == board[1][1] && board[0][0] == board[2][0]) {
            return board[0][2];
        }
    }

    void show_winner(char winner) {

    }

#endif