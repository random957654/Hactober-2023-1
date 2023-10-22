#include <iostream>
using namespace std;

char findMaxRepeating(string input) {
    int length = input.length();
    int maxCount = 0;
    char result = input[0];

    for (int i = 0; i < length; i++) {
        int currentCount = 1;
        
        for (int j = i + 1; j < length; j++) {
            if (input[i] != input[j]) {
                break;
            }
            currentCount++;
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
            result = input[i];
        }
    }
    return result;
}

int main() {
    string inputString = "aaaabbaaccde";
    char maxRepeatingChar = findMaxRepeating(inputString);
    cout << "The maximum repeating character is: " << maxRepeatingChar << endl;
    return 0;
}
