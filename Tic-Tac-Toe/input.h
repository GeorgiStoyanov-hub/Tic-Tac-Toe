#pragma once

#ifndef INPUT_H
#define INPUT_H

#include "logic.h"

void getPlayerMove(unsigned short* row, unsigned short* col);
Cell switchPlayer(Cell currentPlayer);

#endif
