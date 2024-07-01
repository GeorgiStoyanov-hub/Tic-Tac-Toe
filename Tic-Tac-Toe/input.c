#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "input.h"

//vvv menu commands
unsigned short getCommand() {
    unsigned short command;
        if (scanf("%hu", &command) == 1) {
            if (command == 1 || command == 2 || command == 3) // 1 = New Game, 2 = Check Score 3 = Exit
                return command;
            else {
                command = 4;
                return command; // Invalid input
            }
        }
        else {
            command = 4;
            while (getchar() != '\n');
            return command; // Invalid input
        }
}

void getPlayerMove(unsigned short* row, unsigned short* col) {
    unsigned short validInput = 0;
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