#include "logic.h"

void initializeBoard(Cell board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

unsigned short makeMove(Cell board[BOARD_SIZE][BOARD_SIZE], unsigned short row, unsigned short col, Cell player) {
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == EMPTY) {
        board[row][col] = player;
        return 1;
    }
    return 0;
}

unsigned short checkWinner(Cell board[BOARD_SIZE][BOARD_SIZE]) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
    }
    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    // Check diagonals
    if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    // Check for draw or ongoing game
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY)
                return 0; // Game is still ongoing
        }
    }
    return -1; // Draw
}

void initializePoints(score* points) {
    points->score_Player_X = 0.0;
    points->score_Player_O = 0.0;
}

void addPoints(score* points, unsigned short winner) {
    if (winner == PLAYER_X)
        points->score_Player_X++;
    else if (winner == PLAYER_O)
        points->score_Player_O++;
    else {
        points->score_Player_X += 0.5;
        points->score_Player_O += 0.5;
    }

}