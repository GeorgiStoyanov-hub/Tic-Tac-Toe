#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "input.h"

void getPlayerMove(unsigned short* row, unsigned short* col) {
    int validInput = 0;
    while (!validInput) {
        printf("Enter your move (row and column): ");
        if (scanf("%hu %hu", row, col) == 2) {
            // Check if the input is within the allowed range
            if (*row >= 1 && *row <= BOARD_SIZE && *col >= 1 && *col <= BOARD_SIZE) {
                validInput = 1;  // Input is valid
            }
            else {
                printf("Invalid input. Please enter numbers between 1 and %d.\n", BOARD_SIZE);
            }
        }
        else {
            printf("Invalid input. Please enter two numbers.\n");
            while (getchar() != '\n');
        }
    }

    // Adjust the row and column indices entered by the player
    (*row)--;
    (*col)--;
}

Cell switchPlayer(Cell currentPlayer) {
    return currentPlayer == PLAYER_X ? PLAYER_O : PLAYER_X;
}