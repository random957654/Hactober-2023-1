#include <iostream>
using namespace std;

int power(long long x, unsigned int y, int mod)
{
    int res = 1;
    x = x % mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

int main()
{
    const int mod = 1e9 + 7;
    int x, y;
    cin >> x >> y;
    cout << "X ^ Y = " << power(x, y, mod);
    return 0;
}