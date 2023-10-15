#include <iostream>
#include <string>
#include <set>
//A fascinating number is a number that, when multiplied by 2 and 3, and then both results are concatenated with the original number, contains all the digits from 1 to 9 exactly once
bool isFascinating(int num) {
    // Multiply num by 2 and 3
    int num2 = num * 2;
    int num3 = num * 3;

    // Concatenate the three numbers as strings
    std::string concatenated = std::to_string(num) + std::to_string(num2) + std::to_string(num3);

    // Create a set to store unique digits
    std::set<char> uniqueDigits;

    // Check each character in the concatenated string
    for (char digit : concatenated) {
        if (digit >= '1' && digit <= '9') {
            // If it's a digit from 1 to 9, add it to the set
            uniqueDigits.insert(digit);
        } else {
            // If any character is not a digit from 1 to 9, it's not fascinating
            return false;
        }
    }

    // Check if the set contains all digits from 1 to 9
    return uniqueDigits.size() == 9;
}

int main() {
    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;
    
    if (isFascinating(num)) {
        std::cout << num << " is a fascinating number!" << std::endl;
    } else {
        std::cout << num << " is not a fascinating number." << std::endl;
    }

    return 0;
}
