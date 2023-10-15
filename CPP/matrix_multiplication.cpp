#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    size_t rows;
    size_t cols;

public:
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), data(rows, std::vector<int>(cols, 0)) {}

    int& operator()(size_t row, size_t col) {
        return data[row][col];
    }

    const int& operator()(size_t row, size_t col) const {
        return data[row][col];
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Invalid matrix dimensions for multiplication.");
        }

        Matrix result(rows, other.cols);

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result(i, j) += data[i][k] * other(k, j);
                }
            }
        }

        return result;
    }

    void display() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix matrix1(2, 3);
    Matrix matrix2(3, 2);

    // Initialize matrices...

    Matrix result = matrix1 * matrix2;

    std::cout << "Matrix 1:" << std::endl;
    matrix1.display();

    std::cout << "Matrix 2:" << std::endl;
    matrix2.display();

    std::cout << "Result of multiplication:" << std::endl;
    result.display();

    return 0;
}
