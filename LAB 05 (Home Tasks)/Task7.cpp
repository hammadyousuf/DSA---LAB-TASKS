#include <iostream>
using namespace std;
int main()
{
    const int n = 5;
    int maze[n][n] = {
        {1, 0, 1, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 1, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1}};

    int sol[n][n] = {0};
    int x_Stack[100], y_Stack[100], top = -1;
    bool visited[n][n] = {0};
    int x = 0, y = 0;
    x_Stack[++top] = x;
    y_Stack[top] = y;
    visited[x][y] = true;

    while (top >= 0)
    {
        x = x_Stack[top];
        y = y_Stack[top];
        sol[x][y] = 1;
        if (x == n - 1 && y == n - 1)
        {
            break;
        }
        bool moved = false;
        if (y + 1 < n && maze[x][y + 1] == 1 && !visited[x][y + 1])
        {
            y = y + 1;
            x_Stack[++top] = x;
            y_Stack[top] = y;
            visited[x][y] = true;
            moved = true;
        }
        else if (x + 1 < n && maze[x + 1][y] == 1 && !visited[x + 1][y])
        {
            x = x + 1;
            x_Stack[++top] = x;
            y_Stack[top] = y;
            visited[x][y] = true;
            moved = true;
        }
        else if (y - 1 >= 0 && maze[x][y - 1] == 1 && !visited[x][y - 1])
        {
            y = y - 1;
            x_Stack[++top] = x;
            y_Stack[top] = y;
            visited[x][y] = true;
            moved = true;
        }
        else if (x - 1 >= 0 && maze[x - 1][y] == 1 && !visited[x - 1][y])
        {
            x = x - 1;
            x_Stack[++top] = x;
            y_Stack[top] = y;
            visited[x][y] = true;
            moved = true;
        }
        if (!moved)
        {
            sol[x][y] = 0;
            top--;
        }
    }
    cout << "Solution Path:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
