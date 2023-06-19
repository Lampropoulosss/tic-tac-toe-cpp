#ifndef BOT_FUNCTIONS_H
#define BOT_FUNCTIONS_H
#include <iostream>

using std::string;

void bestMove(string T[][3], short int moves, int *bestSquare);
int minimax(string T[][3], short int moves, bool isMaximizing);
bool hasWon(string T[][3], string player);

#endif