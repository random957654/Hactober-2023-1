#include<stdio.h>
int main()
{
	int a[10];
	int i,s=0;
	
	for (i=0;i<10;i++)
	{
		printf("Enter Your Input :");
		scanf("%d",&a[i]);
		if (a[i]%10==0)
		{
			break;
		}
		s=s+1;
	}
	if ((s==1) || (s==0)){
		printf("\nThere are %d number in this Array which does not end with 0.",s);
	}
	else{
		printf("\nThere are %d numbers in this Array which does not end with 0.",s);
	}
}
