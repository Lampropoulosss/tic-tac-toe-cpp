#include "Board.h"
#include <iostream>

Board::Board()
{
    for (short int i = 0; i < 3; i++)
    {
        for (short int j = 0; j < 3; j++)
        {
            this->T[i][j] = " ";
        }
    }
}

void Board::printBoard()
{
    for (short int i = 0; i < 3; i++)
    {
        for (short int j = 0; j < 3; j++)
        {
            std::cout << "|" << this->T[i][j];
        }
        std::cout << "|" << std::endl;
    }
}

void Board::play(Point point, std::string player)
{
    this->T[point.getX()][point.getY()] = player;
    this->moves++;
}

std::string Board::get(Point point)
{
    return this->T[point.getX()][point.getY()];
}

bool Board::hasWon(std::string player)
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        bool rowWin = true;
        for (int j = 0; j < 3; j++)
        {
            if (this->T[i][j] != player)
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
            if (this->T[i][j] != player)
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
        if (this->T[i][i] != player)
        {
            diagonal1Win = false;
        }
        if (this->T[i][2 - i] != player)
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

bool Board::hasWon(std::string T[][3], std::string player)
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

Point Board::bestMove(Point point)
{
    Point bestPoint;

    int bestScore = -800;
    for (short int i = 0; i < 3; i++)
    {
        for (short int j = 0; j < 3; j++)
        {
            if (this->T[i][j] == " ")
            {
                this->T[i][j] = "X";
                int score = minimax(this->T, this->moves + 1, false);
                this->T[i][j] = " ";
                if (score > bestScore)
                {
                    bestScore = score;
                    bestPoint.changePoint(i, j);
                }
            }
        }
    }
    return bestPoint;
}

void Board::increaseMoves()
{
    this->moves++;
}

int Board::getMoves()
{
    return this->moves;
}