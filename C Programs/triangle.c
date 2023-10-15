#include<stdio.h>
int main()
{
   int a, b, c;
   printf("Enter First side of triangle: ");
   scanf("%d",&a);
   printf("Enter Second side of triangle: ");
   scanf("%d",&b);
   printf("Enter Third side of triangle: ");
   scanf("%d",&c);
   if(a == b && b == c)
      printf("The Triangle is equilateral\n");
   else if(a == b || b == c || c == a)
      printf("The Triangle is isosceles\n");
   else
      printf("The Triangle is scalene\n");
   return 0;
}
