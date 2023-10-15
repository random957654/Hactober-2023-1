#include<iostream>
using namespace std;
int main()
{
	int m,temp,i;
	int a[10]={2000,500,200,100,50,20,10,5,2,1};
	cout<<"Enter a Amount : ";
	cin>>m;
	
	temp=m;
	
	for(i=0;i<10;i++)
	{
		cout<<endl<< a[i] <<" notes is : "<<temp/a[i];
		temp=temp%a[i];
	}
	
}
