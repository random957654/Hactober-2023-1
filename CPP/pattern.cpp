#include <iostream>

int main() {
    int n;
    std::cout << "Enter the range: ";
    std::cin >> n;

    // main loop for number of rows
    for (int i = 1; i <= n; ++i) {

        // Loop to print spaces
        for (int j = 1; j <= n - i; ++j) {
            std::cout << " ";
        }

        // Loop to print left side of the triangle
        for (int j = 1; j <= i; ++j) {
            std::cout << j;
        }

        // Loop to print right side of the triangle
        for (int j = i - 1; j >= 1; --j) {
            std::cout << j;
        }

        // Move to the next line after each row is printed
        std::cout << std::endl;
    }

    return 0;
}
