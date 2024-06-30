#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "logic.h"
#include "input.h"
#include "display.h"

int main() {
    Cell board[BOARD_SIZE][BOARD_SIZE];
    Cell currentPlayer = PLAYER_X;
    int winner = 0;

    initializeBoard(board);

    while (!winner) {
        displayBoard(board);
        unsigned short row, col;

        getPlayerMove(&row, &col);

        if (makeMove(board, row, col, currentPlayer)) {
            winner = checkWinner(board);
            if (!winner) {
                currentPlayer = switchPlayer(currentPlayer);
            }
        }
        else {
            printf("Invalid move! Try again.\n");
        }
    }

    displayBoard(board);
    displayWinner(winner);

    return 0;
}