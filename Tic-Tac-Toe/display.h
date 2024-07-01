#pragma once

#ifndef DISPLAY_H
#define DISPLAY_H

#include "logic.h"

void displayBoard(Cell board[BOARD_SIZE][BOARD_SIZE]);
void displayWinner(unsigned short winner);
void displayPoints(const score* points);
void displayMenu();

#endif