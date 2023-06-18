#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;

bool hasWon(string T[][3], string player);
void printBoard(string T[][3]);
void announceWinner(int moves, int mode);
int minimax(string T[][3], short int moves, bool isMaximizing);
void bestMove(string T[][3], short int moves);

int bestX;
int bestY;

int main()
{
    string T[3][3];
    bool end = false;
    short int moves = 0, x, y;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            T[i][j] = " ";
        }
    }

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
            moves += 1;
            do
            {
                cout << "Give cordinates(from 1 to 3)" << endl;
                cin >> x;
                cin.ignore();
                cin >> y;
                cin.ignore();
                x -= 1;
                y -= 1;

                if (x < 0 || x > 2 || y < 0 || y > 2)
                {
                    cout << "Invalid input. The cordinates can only be 1 or 2 or 3." << endl;
                }
            } while ((x < 0 || x > 2) || (y < 0 && y > 2) || T[x][y] != " ");

            if (moves % 2 == 0)
            {
                T[x][y] = "O";
            }
            else
            {
                T[x][y] = "X";
            }

            printBoard(T);

            end = hasWon(T, T[x][y]);

        } while (end == false && moves != 9);
        announceWinner(moves, mode);
    }
    else
    {
        // With the bot

        do
        {
            cout << "Bot's turn." << endl;
            bestMove(T, moves);
            moves++;
            T[bestX][bestY] = "X";
            printBoard(T);
            end = hasWon(T, "X");

            if (!end && moves < 9)
            {
                cout << "Your turn." << endl;
                do
                {
                    cout << "Give cordinates(from 1 to 3)" << endl;
                    cin >> x;
                    cin.ignore();
                    cin >> y;
                    cin.ignore();
                    x -= 1;
                    y -= 1;

                    if (x < 0 || x > 2 || y < 0 || y > 2)
                    {
                        cout << "Invalid input. The cordinates can only be 1 or 2 or 3." << endl;
                    }
                } while ((x < 0 || x > 2) || (y < 0 && y > 2) || T[x][y] != " ");

                moves++;
                T[x][y] = "O";
                printBoard(T);
                end = hasWon(T, "O");
            }
        } while (end == false && moves < 9);

        announceWinner(moves, mode);
    }

    // Program ended, shows "press any key to continue"
    system("pause");

    return 0;
}

bool hasWon(string T[][3], string player)
{
    if ((T[0][0] == T[0][1] && T[0][1] == T[0][2] && T[0][2] == player) ||
        (T[1][0] == T[1][1] && T[1][1] == T[1][2] && T[1][2] == player) ||
        (T[2][0] == T[2][1] && T[2][1] == T[2][2] && T[2][2] == player))
    {
        return true;
    }
    else if ((T[0][0] == T[1][0] && T[1][0] == T[2][0] && T[2][0] == player) ||
             (T[0][1] == T[1][1] && T[1][1] == T[2][1] && T[2][1] == player) ||
             (T[0][2] == T[1][2] && T[1][2] == T[2][2] && T[2][2] == player))
    {
        return true;
    }
    else if ((T[0][0] == T[1][1] && T[1][1] == T[2][2] && T[2][2] == player) ||
             (T[0][2] == T[1][1] && T[1][1] == T[2][0] && T[2][0] == player))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printBoard(string T[][3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << "|" << T[i][0] << "|" << T[i][1] << "|" << T[i][2] << "|" << endl;
    }
}

void announceWinner(int moves, int mode)
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
        else if (moves % 2 == 0)
        {
            cout << "Player won!" << endl;
        }
        else
        {
            cout << "Bot won!" << endl;
        }
    }
}

void bestMove(string T[][3], short int moves)
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
                    bestX = i;
                    bestY = j;
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