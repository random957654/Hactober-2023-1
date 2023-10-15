#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter The Number : ";
	int a;
    cin >> a;
    
    int f = a;
    while(--a)
    {
        f *= a;
    }
    cout << f;
}
