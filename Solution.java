#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minEditDistance(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();

    // Create a 2D array to store the edit distances
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialize the first row and first column
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    // Fill in the dp array
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }

    return dp[m][n];
}

int main() {
    string str1, str2;

    cout << "Enter the first string: ";
    cin >> str1;

    cout << "Enter the second string: ";
    cin >> str2;

    int editDistance = minEditDistance(str1, str2);

    cout << "Minimum Edit Distance: " << editDistance << endl;

    return 0;
}
