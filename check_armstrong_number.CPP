/*This code is to check if a number is an armstrong number
Author: Raunak Mishra
Github: https://github.com/Raunakkumarr
*/ 
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
 int a,on,r,n=0;
 float s=0.0;
 printf("\nEnter the number:\t");
 scanf("%d",&a);
 on=a;
 for(on=a;on!=0;++n){
  on/=10;
 }
 for(on=a;on!=0;on/=10){
  r=on%10;
  s+=pow(r,n);
 }
 if((int)s==a)
  printf("%d is an Armstrong number.",a);
 else
  printf("%d is not an Armstrong number.",a);
 getch();
 return 0;
}