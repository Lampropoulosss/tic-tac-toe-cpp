#pragma once
#include <iostream>
#include "Point.h"
#include "minimax.h"

class Board
{
public:
    Board();
    void play(Point, std::string);
    bool hasWon(std::string);
    static bool hasWon(std::string[][3], std::string);
    std::string get(Point);
    void printBoard();
    Point bestMove(Point);
    void increaseMoves();
    int getMoves();

private:
    std::string T[3][3];
    short int moves = 0;
};