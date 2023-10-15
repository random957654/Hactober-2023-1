#include<stdio.h>
int main()
{
	int a[10];
	 printf("Enter 10 integers: ");
	
	for (int i=0;i<10;i++)
	{
		printf("Enter Your Input :");
		scanf("%d",&a[i]);
	}
	 printf("Displaying integers: ");
	 for(int i = 0; i < 10; ++i) {
     printf("%d\n", a[i]);
  }
	return 0;
}
