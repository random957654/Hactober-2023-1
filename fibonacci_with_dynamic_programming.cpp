#include <bits/stdc++.h>
#define MAXN 100000005
#define MOD 1000000007
using namespace std;

int dp[MAXN];

int fibo(int n)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }

    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    if (n == 2)
    {
        return 1;
    }

    dp[n] = fibo(n - 1) + fibo(n - 2);

    return dp[n];
}

int sumFibo(int l, int r)
{
    int sum = 0;

    while (r >= l)
    {
        sum +=  (fibo(r) % 1000000007);
        r--;
    }
    
    return (sum % 1000000007);
}

int main()
{
    memset(dp, -1, sizeof(dp));

    int repetion;
    int left, right;

    cin >> repetion;

    for (int i = 0; i < repetion; i++)
    {
        cin >> left >> right;
        cout << sumFibo((left % 1000000007), (right % 1000000007));
    }
    return 0;
}