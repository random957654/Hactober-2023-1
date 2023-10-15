#include<stdio.h>
#include<string.h>
void permudation();
void swaping();
int main()
{
    char st[6] ="abcd";
    int n;
    n=strlen(st);
    printf("All Possible combination of ABCD is : \n");
    permudation(st,0,n-1);
    return 0;
}

//function permudation//
void permudation(char *s, int a, int n)         //s=abcd , a=0, n=3
{
    int g;
    if (a==n)
    printf("%s\n",s);
    else{
        for(g=a; g<=n; g++)
        {
            swaping((s+a),(s+g));
            permudation(s,a+1,n);
            swaping((s+a),(s+g));
        }
    }

}

//function swap//
void swaping(char *c1,char *c2)
{
    char temp;
    temp=*c1;
    *c1=*c2;
    *c2=temp;
}
