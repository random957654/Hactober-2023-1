#include<stdio.h>
main()
{
int a,b;
printf("Enter The Value of A: ");
scanf("%d",& a);
printf("Enter The Value of B: ");
scanf("%d",& b);
a=a+b;			//Now Here A = A+B and B = B//
b=a-b;			//Here A= A+B and B = The Inputted value By the User, Now after Substraction B = The Value of A//
a=a-b;			//Here A= A+B and B = The Value of A which I get from previous line, Now After Substraction A = The value of B//
printf("\nAfter Swapping Value of A: %d",a);
printf("\nAfter Swapping Value of B: %d",b);
}
