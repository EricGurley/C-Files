// C programming practice
// Original video: https://youtu.be/_889aB2D1KI
// Cleaned up by: Eric Gurley
// Date: 12/8/2023

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "functions.h"

int main() {

    char winner = ' ';

    reset();

    // The program will run as long 
    // as char winner is NULL (there is no winner yet)
    // and that there is at least 1 open space
    while(winner == ' ' && open_spaces_count() != 0) {

        display();

        user_turn();
        
        winner = determine_winner;

        if (winner != ' ' || open_spaces_count() == 0) {
            break;
        }
    }

    return 0;
}
