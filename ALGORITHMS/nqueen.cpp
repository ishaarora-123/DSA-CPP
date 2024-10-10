#include <iostream>
#include <limits.h>
using namespace std;
int const N = 4;
int board[N][N];
int c = 0;
void printSolution(int board[N][N]) {
    for (int i = 0 ; i < N ; i ++) {
        for (int j = 0 ; j < N ; j ++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(int board[N][N] , int row, int col) {
    int i,j;
    for (i = 0; i < col ; i ++) {
        if (board[row][i] == 1) {
            return false;
        }
    }
    for (i = row, j = col ; i >= 0 && j >= 0 ; i -- , j --) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    for (i = row , j = col ; i < N && j >= 0 ; i ++ , j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}
bool solveNQueen(int board[N][N] , int col) {
    if (col == N) {
        return true;
    }
    for(int i = 0 ; i < N ; i ++) {
        if (isSafe(board , i,col)) {
            board[i][col] = 1;
            if (solveNQueen(board, col+1)) {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}
int main() {
    for (int i = 0 ; i < N ; i ++) {
        for (int j = 0 ; j < N ; j++) {
            board[i][j] = 0;
        }
    } 
    if (solveNQueen(board , 0) == false) {
        cout << "No solution found";
    }
    else {
        printSolution(board);
    }

}