#include<stdio.h>
main()
{
 	int a[]={5,11,12,13,14,55,56,78,85,98,21};
	int i,max,min;
	max=a[0];
	min=a[0];
	for(i=0;i<=9;i++){
		if(a[i]>max){
			max=a[i];
		}
		else{
		max=a[0];
		}
		
		if(a[i]<min){
			min=a[i];
		}
		else{
		min=a[0];
		}	
	}
	printf("%d is Smallest.\n",min);
	printf("%d is Biggest.",max);
	
}
