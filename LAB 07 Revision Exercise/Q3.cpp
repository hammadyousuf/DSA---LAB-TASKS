#include <iostream>
using namespace std;
#define N 4

int maze[N][N] = {
    {1,1,1,1},
    {0,0,0,1},
    {1,1,0,1},
    {1,1,1,1}
};

int sol[N][N] = {0};
int visited[N][N] = {0};

bool isSafe(int x, int y) {
    return x>=0 && y>=0 && x<N && y<N && maze[x][y]==1 and not visited[x][y];
}

bool solve(int x, int y) {
    if (x==0 && y==0) {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(x,y)) {
        cout<<x<<" "<<y<<endl;
        sol[x][y] = 1;
        visited[x][y] = 1;
        if (solve(x-1,y)) return true;
        if (solve(x,y-1)) return true;
        if (solve(x+1, y)) return true;
        if (solve(x, y+1)) return true;
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main() {
    if (solve(2,0)) {
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) cout<<sol[i][j]<<" ";
            cout<<endl;
        }
    }
}