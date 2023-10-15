
#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n)
{

    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i = p * 2; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}

// Driver Program to test above function
int main()
{
    int a;
    cout << "Enter a Number : ";
    cin >> a;
    cout << "Prime numbers smaller than or equal to " << a << endl;
    SieveOfEratosthenes(a);
    return 0;
}
