#include <iostream>
#include <string>
#include <cctype>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int start = 0;
        int end = s.size() - 1;

        while (start <= end) {
            if (!isalnum(s[start])) {
                start++;
                continue;
            }

            if (!isalnum(s[end])) {
                end--;
                continue;
            }

            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            } else {
                start++;
                end--;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    std::string input;
    
    std::cout << "Enter a string to check if it's a palindrome: ";
    std::cin >> input;

    bool isPalindromic = solution.isPalindrome(input);

    if (isPalindromic) {
        std::cout << "The input string is a palindrome." << std::endl;
    } else {
        std::cout << "The input string is not a palindrome." << std::endl;
    }

    return 0;
}