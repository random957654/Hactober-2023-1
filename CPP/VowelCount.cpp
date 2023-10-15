#include <iostream>
#include <string>
using namespace std;

int countVowels(const string& str) {
    int vowelCount = 0;
    for (char c : str) {
        // Convert the character to lowercase for case-insensitive counting
        char lowercaseChar = tolower(c);
        
        // Check if the character is a vowel
        if (lowercaseChar == 'a' || lowercaseChar == 'e' || lowercaseChar == 'i' || lowercaseChar == 'o' || lowercaseChar == 'u') {
            vowelCount++;
        }
    }
    return vowelCount;
}

int main() {
    string input;
    
    cout << "Enter a string: ";
    getline(cin, input);
    
    int result = countVowels(input);
    
    cout << "Number of vowels in the string: " << result << endl;
    
    return 0;
}
