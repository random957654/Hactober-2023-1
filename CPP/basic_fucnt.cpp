#include <iostream>

// Function declaration
int add(int a, int b);

int main() {
    int num1, num2;

    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    // Function call
    int result = add(num1, num2);

    std::cout << "Sum: " << result << std::endl;

    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;
}
