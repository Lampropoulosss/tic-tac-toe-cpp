#include "botFunctions.h"
#include <iostream>

void bestMove(string T[][3], short int moves, int *bestSquare)
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
                    bestSquare[0] = i;
                    bestSquare[1] = j;
                }
            }
        }
    }
}

int minimax(string T[][3], short int moves, bool isMaximizing)
{
    // Check if on terminal state

    if (hasWon(T, "X"))
    {
        return 1;
    }
    else if (hasWon(T, "O"))
    {
        return -1;
    }
    else if (moves == 9 && !hasWon(T, "X") && !hasWon(T, "O"))
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

bool hasWon(string T[][3], string player)
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        bool rowWin = true;
        for (int j = 0; j < 3; j++)
        {
            if (T[i][j] != player)
            {
                rowWin = false;
                break;
            }
        }
        if (rowWin)
        {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++)
    {
        bool colWin = true;
        for (int i = 0; i < 3; i++)
        {
            if (T[i][j] != player)
            {
                colWin = false;
                break;
            }
        }
        if (colWin)
        {
            return true;
        }
    }

    // Check diagonals
    bool diagonal1Win = true;
    bool diagonal2Win = true;
    for (int i = 0; i < 3; i++)
    {
        if (T[i][i] != player)
        {
            diagonal1Win = false;
        }
        if (T[i][2 - i] != player)
        {
            diagonal2Win = false;
        }
    }

    if (diagonal1Win || diagonal2Win)
    {
        return true;
    }

    return false;
}