#pragma once

#ifndef LOGIC_H
#define LOGIC_H

#define BOARD_SIZE 3

typedef enum { EMPTY, PLAYER_X, PLAYER_O } Cell;

void initializeBoard(Cell board[BOARD_SIZE][BOARD_SIZE]);
unsigned short makeMove(Cell board[BOARD_SIZE][BOARD_SIZE], unsigned short row, unsigned short col, Cell player);
unsigned short checkWinner(Cell board[BOARD_SIZE][BOARD_SIZE]);

#endif
