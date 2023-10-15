#include <iostream>
using namespace std;

bool is_valid(int board[9][9], int row, int col, int n) {
    for(int i=0;i<9;i++){
        if(board[i][col] == n){
            return false;
        }
        if(board[row][i] == n){
            return false;
        }
    }
    int sr = (row / 3) * 3;
    int sc = (col / 3) * 3;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (board[sr + r][sc + c] == n) {
                return false;
            }
        }
    }
    return true;
}

bool solve_sudoku(int board[9][9]) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == 0) {
                for (int n = 1; n <= 9; n++) {
                    if (is_valid(board, r, c, n)) {
                        board[r][c] = n;
                        if (solve_sudoku(board)) {
                            return true;
                        }
                        board[r][c] = 0; 
                    }
                }
                return false;  
            }
        }
    }
    return true;  
}

void print_board(int board[9][9]) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
}

int main() {
    int sudoku_board[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solve_sudoku(sudoku_board)) {
        cout << "Sudoku Solved Successfully!" << endl;
        print_board(sudoku_board);
    } 
    else {
        cout << "No Solution Found!" << endl;
    }
    return 0;
}

