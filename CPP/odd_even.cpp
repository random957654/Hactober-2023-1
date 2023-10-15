#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of values to be checked : ";
    cin >> n;
	// multiple values to be determined.
    while(n--)
    {
        int a;
        cout<<"Enter a Number : ";
        cin>>a;

        cout << "The number is ";
	    // ternary operator to determine the output in less space.
        (a%2) ? cout << "Odd Number \n" : cout << "Even Number \n";
    }
}
