#include <iostream>
using namespace std;

bool isSafe(int board[20][20], int row, int col, int n) {
    for (int i=0;i<row;i++) if (board[i][col]) return false;
    for (int i=row-1,j=col-1;i>=0 && j>=0;i--,j--) if (board[i][j]) return false;
    for (int i=row-1,j=col+1;i>=0 && j<n;i--,j++) if (board[i][j]) return false;
    return true;
}

bool solve(int board[20][20], int row, int n) {
    if (row==n) {
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) cout<<(board[i][j] ? "Q " : "- ");
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    bool res=false;
    for (int i=0;i<n;i++) {
        if (isSafe(board,row,i,n)) {
            board[row][i]=1;
            res = solve(board,row+1,n) || res;
            board[row][i]=0;
        }
    }
    return res;
}

int main() {
    int n=4;
    int board[20][20]={0};
    solve(board,0,n);
}