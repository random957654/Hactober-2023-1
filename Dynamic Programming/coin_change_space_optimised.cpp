#include <bits/stdc++.h>
using namespace std;

int count(int coins[], int n, int sum)
{
    int dp[sum + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 0; i < n; i++)
        for (int j = coins[i]; j <= sum; j++)
            dp[j] += dp[j - coins[i]];

    return dp[sum];
}

int main()
{
    int coins[] = { 1, 2, 3 };
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum = 5;
    cout << count(coins, n, sum);
    return 0;
}
