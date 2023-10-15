#include<stdio.h>
int main()
{
    int num, inp, rev=0, rm;
    printf("Enter a Number: ");
    scanf("%d", &num);
    inp = num;
    while(num>0)
    {
        rm = num%10;
        rev = (rev*10)+rm;
        num = num/10;
    }
    if(inp==rev){
        printf("\nThis number is equal to it's Reverse Number.");
    }
    else{
        printf("\nThis number is not equal to it's Reverse Number.");
    }
    return 0;
}
