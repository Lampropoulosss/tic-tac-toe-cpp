#include <iostream>
#include "minimax.h"

using std::string;

int minimax(string T[][3], int moves, bool isMaximizing)
{
    // Check if on terminal state

    if (Board::hasWon(T, "X"))
    {
        return 1;
    }
    else if (Board::hasWon(T, "O"))
    {
        return -1;
    }
    else if (moves == 9 && !Board::hasWon(T, "X") && !Board::hasWon(T, "O"))
    {
        return 0;
    }

    if (isMaximizing)
    {
        int bestScore = -800;
        for (short int i = 0; i < 3; i++)
        {
            for (short int j = 0; j < 3; j++)
            {
                if (T[i][j] == " ")
                {
                    T[i][j] = "X";
                    int score = minimax(T, moves + 1, false);
                    T[i][j] = " ";
                    if (score > bestScore)
                    {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
    else
    {
        int bestScore = 800;
        for (short int i = 0; i < 3; i++)
        {
            for (short int j = 0; j < 3; j++)
            {
                if (T[i][j] == " ")
                {
                    T[i][j] = "O";
                    int score = minimax(T, moves + 1, true);
                    T[i][j] = " ";
                    if (score < bestScore)
                    {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
}