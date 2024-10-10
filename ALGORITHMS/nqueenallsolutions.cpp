#include <iostream>
using namespace std;
int const N = 6;
int board[N][N];
int c = 0;
void printSolution(int board[N][N]) {
    for (int i = 0 ; i < N ; i ++) {
        for (int j = 0 ; j < N ; j ++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
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
bool solveNQueen(int board[N][N] ,int col) {
    if (col == N) {
        printSolution(board);
        c = c + 1;
    }
    for(int i = 0 ; i < N ; i ++) {
        if (isSafe(board , i,col)) {
            board[i][col] = 1;
            if (solveNQueen(board, (col+1))) {
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
    if(N == 2 || N ==3)
        cout<<"No solution";
    else{
        bool r = solveNQueen(board, 0);
        cout<<"\nTotal no of distinct solutions : "<<c;
    }
}