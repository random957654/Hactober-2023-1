#include<iostream>
#include<vector>
using namespace std;

const int N = 8;
int board[N][N];
int moveCount = 0;

vector<pair<int, int>> validMoves(int row, int col) {
    vector<pair<int, int>> moves;
    int rowMoves[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int colMoves[] = {1, 2, 2, 1, -1, -2, -2, -1};
    for (int i = 0; i < 8; i++) {
        int newRow = row + rowMoves[i];
        int newCol = col + colMoves[i];
        if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N && board[newRow][newCol] == 0) {
            moves.push_back(make_pair(newRow, newCol));
        }
    }
    return moves;
}

bool solve(int row, int col, int moveNum) {
    board[row][col] = moveNum;
    moveCount++;

    if (moveNum == N*N) {
        return true;
    }

    vector<pair<int, int>> moves = validMoves(row, col);
    for (pair<int, int> move : moves) {
        int newRow = move.first;
        int newCol = move.second;
        if (solve(newRow, newCol, moveNum+1)) {
            return true;
        }
    }

    board[row][col] = 0;
    moveCount--;
    return false;
}

int main() {
    int startRow = 0, startCol = 0;
    solve(startRow, startCol, 1);
    cout << "Number of moves: " << moveCount << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
