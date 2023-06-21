#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Point.h"
#include "Board.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void announceWinner(Board board, int moves, int mode);

int main()
{
    Board board;
    Point point;
    bool end = false;

    // Ask whether you want to play with the bot or with another player
    cout << "Want to play with the bot or another player? (1 or 2)\n1) Bot\n2) Player" << endl;

    int mode;
    do
    {
        cin >> mode;
        cin.ignore();
        if (mode != 1 && mode != 2)
        {
            cout << "Invalid input" << endl;
        }
    } while (mode != 1 && mode != 2);

    // With another player
    if (mode == 2)
    {
        cout << "Player one you are X and player two you are O" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        do
        {
            // board.increaseMoves();
            do
            {
                short int x, y;
                cout << "Give cordinates(from 1 to 3)" << endl;
                cin >> x;
                cin.ignore();
                cin >> y;
                cin.ignore();
                x -= 1;
                y -= 1;
                point.changeX(x);
                point.changeY(y);

                if (point.getX() < 0 || point.getX() > 2 || point.getY() < 0 || point.getY() > 2)
                {
                    cout << "Invalid input. The cordinates can only be 1 or 2 or 3." << endl;
                }
            } while ((point.getX() < 0 || point.getX() > 2) || (point.getY() < 0 && point.getY() > 2) || board.get(point) != " ");

            if (board.getMoves() % 2 == 0)
            {
                board.play(point, "O");
            }
            else
            {
                board.play(point, "X");
            }

            board.printBoard();

            end = board.hasWon(board.get(point));

        } while (end == false && board.getMoves() != 9);
        announceWinner(board, board.getMoves(), mode);
    }
    else
    {
        // With the bot

        std::srand(std::time(0));

        int randomNumber = (std::rand() % 2) + 1;

        cout << "The player who starts is chosen randomly" << endl;

        if (randomNumber == 1)
        {
            do
            {
                cout << "Bot's turn." << endl;
                point.changePoint(board.bestMove(point));
                board.play(point, "X");
                board.printBoard();

                end = board.hasWon("X");

                if (!end && board.getMoves() < 9)
                {
                    cout << "Your turn." << endl;
                    do
                    {
                        short int x, y;
                        cout << "Give cordinates(from 1 to 3)" << endl;
                        cin >> x;
                        cin.ignore();
                        cin >> y;
                        cin.ignore();
                        x -= 1;
                        y -= 1;
                        point.changeX(x);
                        point.changeY(y);

                        if (x < 0 || x > 2 || y < 0 || y > 2)
                        {
                            cout << "Invalid input. The cordinates can only be 1 or 2 or 3." << endl;
                        }
                    } while ((point.getX() < 0 || point.getX() > 2) || (point.getY() < 0 && point.getY() > 2) || board.get(point) != " ");

                    board.play(point, "O");
                    board.printBoard();

                    end = board.hasWon("O");
                }
            } while (end == false && board.getMoves() < 9);
        }
        else
        {
            do
            {
                cout << "Your turn." << endl;
                do
                {
                    short int x, y;
                    cout << "Give cordinates(from 1 to 3)" << endl;
                    cin >> x;
                    cin.ignore();
                    cin >> y;
                    cin.ignore();
                    x -= 1;
                    y -= 1;
                    point.changeX(x);
                    point.changeY(y);

                    if (x < 0 || x > 2 || y < 0 || y > 2)
                    {
                        cout << "Invalid input. The cordinates can only be 1 or 2 or 3." << endl;
                    }
                } while ((point.getX() < 0 || point.getX() > 2) || (point.getY() < 0 && point.getY() > 2) || board.get(point) != " ");

                board.play(point, "O");
                board.printBoard();
                end = board.hasWon("O");

                if (!end && board.getMoves() < 9)
                {
                    cout << "Bot's turn." << endl;
                    point.changePoint(board.bestMove(point));

                    board.play(point, "X");
                    board.printBoard();

                    end = board.hasWon("X");
                }

            } while (end == false && board.getMoves() != 9);
        }

        announceWinner(board, board.getMoves(), mode);
    }

    // Program ended, shows "press any key to continue"
    system("pause");

    return 0;
}

// Functions and utilities

void announceWinner(Board board, int moves, int mode)
{
    if (mode == 2)
    {
        if (moves == 9)
        {
            cout << "This match is a tie." << endl;
        }
        else if (moves % 2 == 0)
        {
            cout << "Player two won!" << endl;
        }
        else
        {
            cout << "Player one won!" << endl;
        }
    }
    else
    {
        if (moves == 9)
        {
            cout << "This match is a tie." << endl;
        }
        else if (board.hasWon("O"))
        {
            cout << "Player won!" << endl;
        }
        else if (board.hasWon("X"))
        {
            cout << "Bot won!" << endl;
        }
    }
}