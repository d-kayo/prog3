#include <iostream>
#include <vector>
using namespace std;


bool safe(vector<int> board, int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}


void solve(int n, int row, vector<int> board, vector<vector<int>>& solutions) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }
    
    for (int col = 0; col < n; ++col) {
        if (safe(board, row, col)) {
            board[row] = col;
            solve(n, row + 1, board, solutions);
        }
    }
}


void printSolutions(vector<vector<int>> solutions, int n) {
    cout << "Total solutions: " << solutions.size() << endl;
    for (vector<int> board : solutions) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << (board[i] == j ? "1 " : "0 ");
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> solutions;
    vector<int> board(n, -1);
    solve(n, 0, board, solutions);
    
    printSolutions(solutions, n);
    
    return 0;
}
