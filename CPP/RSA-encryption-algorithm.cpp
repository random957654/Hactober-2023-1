#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

int main() {
    // Step 1: Choose two large prime numbers
    int p = 61;
    int q = 53;

    // Step 2: Calculate n and phi(n)
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Step 3: Choose public key e
    int e = 17;

    // Step 4: Calculate private key d
    int d = modInverse(e, phi);

    // Step 5: Encrypt and Decrypt
    int message = 88;
    int encrypted = int(pow(message, e)) % n;
    int decrypted = int(pow(encrypted, d)) % n;

    cout << "Original message: " << message << endl;
    cout << "Encrypted message: " << encrypted << endl;
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}
