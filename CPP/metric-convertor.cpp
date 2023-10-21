#include <iostream>

// Function to convert meters to centimeters
double metersToCentimeters(double meters) {
    return meters * 100.0;
}

// Function to convert meters to millimeters
double metersToMillimeters(double meters) {
    return meters * 1000.0;
}

// Function to convert centimeters to meters
double centimetersToMeters(double centimeters) {
    return centimeters / 100.0;
}

// Function to convert millimeters to meters
double millimetersToMeters(double millimeters) {
    return millimeters / 1000.0;
}

int main() {
    int choice;
    double value;

    std::cout << "Metric Conversion Program" << std::endl;
    std::cout << "1. Meters to Centimeters" << std::endl;
    std::cout << "2. Meters to Millimeters" << std::endl;
    std::cout << "3. Centimeters to Meters" << std::endl;
    std::cout << "4. Millimeters to Meters" << std::endl;
    std::cout << "Enter your choice (1-4): ";
    std::cin >> choice;

    if (choice < 1 || choice > 4) {
        std::cout << "Invalid choice. Please select a valid option (1-4)." << std::endl;
        return 1;
    }

    std::cout << "Enter the value to convert: ";
    std::cin >> value;

    double result;
    switch (choice) {
        case 1:
            result = metersToCentimeters(value);
            std::cout << value << " meters is equal to " << result << " centimeters." << std::endl;
            break;
        case 2:
            result = metersToMillimeters(value);
            std::cout << value << " meters is equal to " << result << " millimeters." << std::endl;
            break;
        case 3:
            result = centimetersToMeters(value);
            std::cout << value << " centimeters is equal to " << result << " meters." << std::endl;
            break;
        case 4:
            result = millimetersToMeters(value);
            std::cout << value << " millimeters is equal to " << result << " meters." << std::endl;
            break;
    }

    return 0;
}