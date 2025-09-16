#include <iostream>
using namespace std;
bool isSafe(int maze[4][4], int x, int y, int sol[4][4])
{
    if (x >= 0 && x < 4 && y >= 0 && y < 4 && maze[x][y] == 1 && sol[x][y] == 0)
    {
        return true;
    }
    return false;
}
bool solveMaze(int maze[4][4], int x, int y, int sol[4][4])
{
    if (x == 2 && y == 0)
    {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y, sol))
    {
        sol[x][y] = 1;

        if (solveMaze(maze, x + 1, y, sol))
        {
            return true;
        }
        if (solveMaze(maze, x, y + 1, sol))
        {
            return true;
        }
        if (solveMaze(maze, x - 1, y, sol))
        {
            return true;
        }
        if (solveMaze(maze, x, y - 1, sol))
        {
            return true;
        }
        sol[x][y] = 0;
        return false;
    }
    return false;
}
int main()
{
    int maze[4][4] = {
        {1, 1, 1, 1},
        {0, 0, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1}};

    int sol[4][4] = {0};

    if (solveMaze(maze, 0, 0, sol))
    {
        cout << "Path found:\n";
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No path exists.\n";
    }
    return 0;
}
