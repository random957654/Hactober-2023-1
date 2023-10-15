// C++ program to Count set bits in an integer
#include <iostream>
using namespace std;

    /* Function to get no of set bits in binary
representation of passed binary no. */
    unsigned int countSetBits(int n)
    {
        unsigned int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
/* Program to test function countSetBits */
int main()
{
    int n;
    cout<<"\n enter the number = ";
    cin>>n;
    cout << countSetBits(n);
    return 0;
}