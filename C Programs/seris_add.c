#include<stdio.h>
int main()
{
    int i;
    float a=1.0, res1, res2=0;


    for (i=1;i<=10;i++)
    {
       
        a = a * i;

        res1 = i/a;

        res2 = res2 + res1;
    }

    printf("The Addition of the seris is : %f", res2);
    return 0;
}