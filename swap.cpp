// C++ program for illustration of swap() function 
#include <bits/stdc++.h> 

#include <iostream>
using namespace std;

int main() {
    int a;
    int b;

    cout << "Enter value of a: ";
    cin >> a;

    cout << "Enter value of b: ";
    cin >> b;

    // Swap values of the variables
    swap(a, b);

    cout << "Value of a now: " << a << endl;
    cout << "Value of b now: " << b << endl;

    return 0;
}
