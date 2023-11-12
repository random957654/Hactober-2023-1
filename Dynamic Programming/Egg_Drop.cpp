#include <vector>
#include <algorithm>

class Solution {
public:
    int twoEggDrop(int f) {
        std::vector<std::vector<int>> dp(3, std::vector<int>(f + 1, 0));

        for (int i = 1; i <= 2; ++i) {
            for (int j = 1; j <= f; ++j) {
                if (i == 1) {
                    dp[i][j] = j;
                } else if (j == 1) {
                    dp[i][j] = 1;
                } else {
                    int mn = INT_MAX;
                    int low, high;

                    int left = 1, right = j;
                    while (left <= right) {
                        int mid = left + (right - left) / 2;

                        low = dp[i - 1][mid - 1];
                        high = dp[i][j - mid];

                        mn = std::min(mn, 1 + std::max(low, high));

                        if (low < high) {
                            left = mid + 1;
                        } else if (low > high) {
                            right = mid - 1;
                        } else {
                            break;  // found the optimal value
                        }
                    }

                    dp[i][j] = mn;
                }
            }
        }

        return dp[2][f];
    }
};
