#include <iostream>
#include <random>

int main() {
    int min, max;

    // Input the range (minimum and maximum values)
    std::cout << "Enter the minimum value: ";
    std::cin >> min;
    std::cout << "Enter the maximum value: ";
    std::cin >> max;

    // Create a random number generator
    std::random_device rd;  // Obtain a random seed from the OS
    std::mt19937 generator(rd());  // Initialize the Mersenne Twister pseudo-random number generator
    std::uniform_int_distribution<int> distribution(min, max);  // Define the range

    // Generate a random number within the specified range
    int random_number = distribution(generator);

    // Display the random number
    std::cout << "Random number within the range [" << min << ", " << max << "]: " << random_number << std::endl;

    return 0;
}