#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    bool palindrome = isPalindrome(input);
    if (palindrome)
        cout << "It's a palindrome." << endl;
    else
        cout << "It's not a palindrome." << endl;
    return 0;
}