#include<stdio.h>
#include<math.h>


void main(){
	float a,b,c;
	
	printf("For the equation ax^2 + bx + c = 0 , enter the constants a,b and c (a=/=0)\n");
	scanf("%f %f %f",&a,&b,&c);
	
	float d=pow(b,2)-(4*a*c);
	printf("The discriminant is %.2f\n",d);
	float r1,r2;
	if(d>0)
	{
		printf("Since the discriminant is positive, hence, the roots are real and distinct as follows\n");
		r1=((-b)+sqrt(d))/(2*a);
		r2=((-b)-sqrt(d))/(2*a);
		printf("Root 1: %.2f\n",r1);
		printf("Root 2: %.2f",r2);
	}
	
	else if(d==0){
		printf("Since the discriminant is 0, hence, the roots are real and equal as follows\n");
		r1=(-b)/(2*a);
		r2=r1;
		printf("Root 1: %.2f\n",r1);
		printf("Root 2: %.2f",r2);
	}
	else{
		printf("Since the discriminant is negative, hence, the roots are imaginary as follows\n");
		float x = (-b)/(2*a);
        float y = sqrt(-d)/(2*a);
        printf("Root 1: %.2f-i.%.2f\n",x,y);
		printf("Root 2: %.2f+i.%.2f",x,y);
	}
	
	
	
}
