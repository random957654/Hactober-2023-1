#include <iostream>
#include <vector>
using namespace std;

bool is_attack(int i, int j, vector<vector<int>> &board, int n) {
    for (int k = 0; k < n; k++) {
        if (board[i][k] == 1 || board[k][j] == 1) {
            return true;
        }
    }
    for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
            if ((k + l == i + j) || (k - l == i - j)) {
                if (board[k][l] == 1) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool n_queen_helper(vector<vector<int>> &board, int col, int n) {
    if (col >= n) {
        return true;
    }
    for (int i = 0; i < n; i++) {
        if (!is_attack(i, col, board, n)) {
            board[i][col] = 1;
            if (n_queen_helper(board, col + 1, n)) {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}

void print_board(vector<vector<int>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void n_queen(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (!n_queen_helper(board, 0, n)) {
        cout << "Solution does not exist" << endl;
        return;
    }
    print_board(board);
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    n_queen(n);
}
