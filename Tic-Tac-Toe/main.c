#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "logic.h"
#include "input.h"
#include "display.h"

int main() {
    Cell board[BOARD_SIZE][BOARD_SIZE];
    Cell currentPlayer = PLAYER_X;
    unsigned short winner = 0;
    unsigned short command = 0;
    score points;
    initializePoints(&points);

    while (command != 3) {

        displayMenu();

        command = getCommand();

        if (command == 1) {
            initializeBoard(board);

            while (!winner) {
                unsigned short row, col;

                displayBoard(board);

                getPlayerMove(&row, &col);

                if (makeMove(board, row, col, currentPlayer)) {
                    winner = checkWinner(board);
                    if (winner) {
                        addPoints(&points, winner);
                    }
                    currentPlayer = switchPlayer(currentPlayer);
                }
                else {
                    printf("Invalid move! Try again.\n");
                }
            }

            displayBoard(board);
            displayWinner(winner);
        }
        else if (command == 2)
            displayPoints(&points);
        else if (command == 3) {
            printf("\nThank you for playing!\n");
            return 0;
        }
        else {
            printf("\nInvalid input!\n");
        }
    }

    return 0;
}