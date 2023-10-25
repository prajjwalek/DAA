#include <iostream>
using namespace std;

int board[10][10] = {0};

bool isSafe(int row, int col, int n) {
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(int row, int n) {
    if (row == n) {
        return true; 
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(row, col, n)) {
            board[row][col] = 1;

            if (solveNQueens(row + 1, n)) {
                return true;
            }

            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    if (n <= 0 || n > 10) {
        cout << "Invalid input for N." << endl;
        return 1;
    }

    if (solveNQueens(0, n)) {
        cout << "Solution found:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
