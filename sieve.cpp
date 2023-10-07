// to find out primes in an optimized approach using the Sieve of Eratosthenes
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the upper limit (n): ";
    cin>>n;
    bool* isPrime=new bool[n+1];
    memset(isPrime,true,sizeof(bool)*(n+1));
    // vector<bool> isPrime(n+1,true);
    for(int i=2;i*i<=n;i++)
    if(isPrime[i])
    for(int j=i*i;j<=n;j+=i)
    isPrime[j]=false;
    cout<<"The Prime Numbers from 1 - "<<n<<" (n) are: ";
    for(int i=2;i<=n;i++)
    if(isPrime[i])
    cout<<i<<" ";
    return(0);
}//end of main