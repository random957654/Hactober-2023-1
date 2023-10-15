#include <iostream>
#include <vector>

void generateSpiralMatrix(int n) {
    std::vector<std::vector<int>> spiral(n, std::vector<int>(n, 0));

    int row_start = 0, row_end = n - 1;
    int col_start = 0, col_end = n - 1;
    int num = 1;

    while (row_start <= row_end && col_start <= col_end) {
        // Traverse right
        for (int i = col_start; i <= col_end; i++) {
            spiral[row_start][i] = num++;
        }
        row_start++;

        // Traverse down
        for (int i = row_start; i <= row_end; i++) {
            spiral[i][col_end] = num++;
        }
        col_end--;

        // Traverse left
        for (int i = col_end; i >= col_start; i--) {
            spiral[row_end][i] = num++;
        }
        row_end--;

        // Traverse up
        for (int i = row_end; i >= row_start; i--) {
            spiral[i][col_start] = num++;
        }
        col_start++;
    }

    // Print the spiral matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << spiral[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the size of the spiral matrix: ";
    std::cin >> n;

    generateSpiralMatrix(n);

    return 0;
}
