//area of a triangle
#include<stdio.h>
#include<math.h>
int main(){
    int a,b,c,s,area;
    printf("enter side 1:\n");
    scanf("%d",&a);
    printf("enter side 2:\n");
    scanf("%d",&b);
    printf("enter side 3:\n");
    scanf("%d",&c);
    s=(a+b+c)/2;
    area=sqrt( s*(s-a)*(s-b)*(s-c) );
    if(area<1){
        printf("invalid values for sides\n");
        main();//reruns the loop once again
    }else{
        printf("The area of triangle is %d",area);

    }
    
    return 0;

}

