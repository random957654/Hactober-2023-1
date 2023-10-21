#include <iostream>

int main() {
    // Declare variables for weight and height
    double weight, height;

    // Prompt the user to enter their weight (in kg)
    std::cout << "Enter your weight (in kilograms): ";
    std::cin >> weight;

    // Prompt the user to enter their height (in meters)
    std::cout << "Enter your height (in meters): ";
    std::cin >> height;

    // Calculate BMI
    double bmi = weight / (height * height);

    // Display the BMI
    std::cout << "Your BMI is: " << bmi << std::endl;

    // Interpret the BMI value
    if (bmi < 18.5) {
        std::cout << "You are underweight." << std::endl;
    } else if (bmi >= 18.5 && bmi < 24.9) {
        std::cout << "You have a normal weight." << std::endl;
    } else if (bmi >= 25.0 && bmi < 29.9) {
        std::cout << "You are overweight." << std::endl;
    } else {
        std::cout << "You are obese." << std::endl;
    }

    return 0;
}