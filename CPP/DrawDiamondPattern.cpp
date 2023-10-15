#include <iostream>

void drawDiamondPattern(int n) {
    if (n <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return;
    }

    // Upper half of the diamond
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            std::cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    // Lower half of the diamond (excluding the center row)
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            std::cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;

    // Input the value of n
    std::cout << "Enter a positive integer n: ";
    std::cin >> n;

    drawDiamondPattern(n);

    return 0;
}
