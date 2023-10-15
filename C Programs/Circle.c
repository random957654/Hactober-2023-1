#include <stdio.h>

int main ()
{
    float radius,circu;
    float dia,area;
    printf("Enter Radius:");
    scanf("%f", &radius);
        

    dia = 2*radius;
    
    circu = 2* 3.14 * radius;
    
    area = 3.14 * (radius * radius);

    printf("Diameter is %f\n",dia);
    printf ("Circumference of the Circle is %f\n ",circu);
    printf("Area of the circle is %f\n",area);
    
    
    return 0;


}
