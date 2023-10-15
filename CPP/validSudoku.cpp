#include <iostream>
#include <vector>

class Solution {
public:
    bool helper(std::vector<std::vector<char>>& board, char val, int r, int c) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == val && i != c) {
                return false;
            }
            if (board[i][c] == val && i != r) {
                return false;
            }
            if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == val && r != (3 * (r / 3) + i / 3) && (3 * (c / 3) + i % 3) != c) {
                return false;
            }
        }

        return true;
    }

    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    bool val = helper(board, board[i][j], i, j);
                    if (val == false) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<char>> sudokuBoard = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    bool valid = solution.isValidSudoku(sudokuBoard);

    if (valid) {
        std::cout << "The Sudoku board is valid." << std::endl;
    } else {
        std::cout << "The Sudoku board is not valid." << std::endl;
    }

    return 0;
}
