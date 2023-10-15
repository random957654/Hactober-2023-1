#include <iostream>
using namespace std;

const int MAX = 10;

void transposeMatrix(int matrix[MAX][MAX], int row, int col) {
    int transposed[MAX][MAX];

    // Moving matrix elements to the transposed matrix.
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    // Displaying the transposed matrix.
    cout << "Transposed Matrix:" << endl;
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int row = 3, col = 3;
    int matrix[MAX][MAX] = {{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}};

    // Calling a function to perform the transpose.
    transposeMatrix(matrix, row, col);

    return 0;
}
