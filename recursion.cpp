#include <iostream>

int factorial(int n) {
    
    if (n <= 1) {
        return 1;
    }
   
    return n * factorial(n - 1);
}

int main() {
    int n;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
    } else {
        int result = factorial(n);
        std::cout << "Factorial of " << n << " is " << result << std::endl;
    }

    return 0;
}
