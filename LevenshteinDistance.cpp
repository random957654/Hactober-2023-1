#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the minimum of three numbers
int min(int x, int y, int z) {
    return min(min(x, y), z);
}

int minEditDistance(string str1, string str2, int m, int n) {
    // Create a table to store results of subproblems
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Fill d[][] in bottom up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If first string is empty, insert all characters of second string
            if (i == 0)
                dp[i][j] = j;

            // If second string is empty, remove all characters of first string
            else if (j == 0)
                dp[i][j] = i;

            // If last characters are same, ignore last character and get count for remaining characters.
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            // If last character are different, consider all possibilities and find minimum
            else
                dp[i][j] = 1 + min(dp[i][j - 1],      // Insert
                                   dp[i - 1][j],      // Remove
                                   dp[i - 1][j - 1]); // Replace
        }
    }

    return dp[m][n];
}

int main() {
    string str1, str2;
    cout << "Enter string 1: ";
    cin >> str1;
    cout << "Enter string 2: ";
    cin >> str2;

    int distance = minEditDistance(str1, str2, str1.length(), str2.length());
    cout << "Minimum edit distance: " << distance << endl;

    return 0;
}
