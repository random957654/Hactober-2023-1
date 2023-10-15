#include <bits/stdc++.h>
using namespace std;

int prime(int n)
{
    for(int i = 2; i < sqrt(n); i++)
    {
        if(!(n%i)){return 0;}
    }
    return 1;
}

int main()
{
    /* code */
    int n;
    cout<<"enter a number = ";
    cin>>n;
    if(n<2){cout<<"it is neither prime, nor composite";}
    else if(prime(n)){cout<<"it is prime";}
    else if(!prime(n)){cout<<"it is composite";}
    return 0;
}
