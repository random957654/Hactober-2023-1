#include <bits/stdc++.h>
using namespace std;
bool ispow2(int n)
{
    return (n && !(n&(n-1)));
}
int main()
{
	cout<<"ENTER THE NO: ";
	int x;
	cin>>x;
    if(ispow2(x))
	  cout<<"TRUE";
    else
      cout<<"FALSE";
	return 0;
}
