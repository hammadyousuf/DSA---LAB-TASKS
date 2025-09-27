#include <iostream>
using namespace std;
const int n = 6;
bool isSafe(int board[n][n], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

bool solve_Queens(int board[n][n], int row)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-------------------" << endl;
        return true;
    }

    bool found = false;
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;
            found = solve_Queens(board, row + 1) || found;
            board[row][col] = 0;
        }
    }
    return found;
}
int main()
{
    int board[n][n] = {0};
    cout << "All possible solutions for placing flags on a 4x4 grid:" << endl;
    solve_Queens(board, 0);
    cout << "Maximum number of flags that can be placed = " << n << endl;
    return 0;
}
