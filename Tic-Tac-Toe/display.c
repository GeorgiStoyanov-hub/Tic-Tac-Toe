#include <stdio.h>
#include "display.h"

void displayMenu(){
    printf("\nWelcome to TicTacToe!");
    printf("\nPress 1 to start a new game.");
    printf("\nPress 2 to see the score.");
    printf("\nPress 3 to exit.\n");
    printf("Command: ");
}

void displayBoard(Cell board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == PLAYER_X) {
                printf(" X ");
            }
            else if (board[i][j] == PLAYER_O) {
                printf(" O ");
            }
            else {
                printf("   ");
            }
            if (j < BOARD_SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

void displayWinner(unsigned short winner) {
    if (winner == PLAYER_X) {
        printf("Player X wins!\n");
    }
    else if (winner == PLAYER_O) {
        printf("Player O wins!\n");
    }
    else {
        printf("It's a draw!\n");
    }
}

void displayPoints(const score* points) {
    printf("Points:\n");
    printf("Player X: %.1lf\n", points->score_Player_X);
    printf("Player O: %.1lf\n", points->score_Player_O);
}