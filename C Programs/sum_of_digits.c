#include<stdio.h>
int main()
{
	int n,b,a,s=0;
	printf("Enter a number :");
	scanf("%d",&n);
	b=n;
	while(n!=0){
		a=n%10;
		s=s+a;
		n=n/10;
	}
	printf("Sum of %d Digits are %d",b,s);
}
