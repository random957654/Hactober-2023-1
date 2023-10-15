#include<stdio.h>
int main()
{
	int amt,dis;
	printf("Enter Your Amount of Purchase : ");
	scanf("%d",&amt);
	
	if 	((amt>0) && (amt<=2000)){
		printf("\nYour Gift is : Calculator");
		dis=(amt-(amt*5/100));
		printf("\nYour Total Amount After Discount Is : %d",dis);
	}
	
	else if ((amt>2000) && (amt <=5000)){
		printf("\nYour Gift is : School Bag");
		dis=(amt-(amt*10/100));
		printf("\nYour Total Amount After Discount Is : %d",dis);
	}
	
	else if ((amt>5000) && (amt <=10000)){
		printf("\nYour Gift is : Wall Clock");
		dis=(amt-(amt*15/100));
		printf("\nYour Total Amount After Discount Is : %d",dis);
	}
	
	else {
		printf("\nYour Gift is : Wrist Watch");
		dis=(amt-(amt*20/100));
		printf("\nYour Total Amount After Discount Is : %d",dis);
	}
}

