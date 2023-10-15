#include<stdio.h>
void main(){
int n;
printf("Enter n:");
scanf("%d",&n);
int a[n],b[n];
printf("enter the plots area:");
for(int i=0;i<n;i++){
  scanf("%d",&a[i]);
}
int sum=0;
printf("enter the cost of plots:");
  for(int j=0;j<n;j++){
        scanf("%d",&b[j]);
    }
    printf("cost of total merged area:");
    for(int i=0;i<n;i++){
        sum=sum+a[i]*b[i];
    }
    printf("%d",sum);
}
