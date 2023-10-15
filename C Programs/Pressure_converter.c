#include <stdio.h>

int main() {
    int i;
    float value;
    
    printf("Enter The No. of conversion you want\n");
    printf("1. Hectopascal to Megapascal\n");
    printf("2. Megapascal to Hectopascal\n");
    printf("3. Millimetre of Hg to Millibar\n");
    printf("4. Millibar to Millimetre of Hg\n");
    printf("5. Inch of Hg to Bar\n");
    printf("6. Bar to Inch of Hg\n");
    printf("7. Kilopascal to Bar\n");
    printf("8. Bar to Kilopascal\n");
    printf("9. Standard Pressure(atm) to Pounds/Square Inch\n");
    printf("10. Pounds/Square Inch to Standard Pressure(atm)\n");
    printf("11. Standard Pressure(atm) to Bar\n");
    printf("12. Bar to Standard Pressure(atm)\n");

    scanf("%d", &i);

    if (i==1)
    {
        printf("Enter the value in Hectopascal\n");
        scanf("%f", &value);
        printf("Equals to %f Megapascal", value/10000);
    } 
    else if (i==2)
    {
        printf("Enter the value in Megapascal\n");
        scanf("%f", &value);
        printf("Equals to %f Hectopascal", value*10000);
    }  
    else if (i==3)
    {
        printf("Enter the value in Millimetre of Hg\n");
        scanf("%f", &value);
        printf("Equals to %f Millibar", value*1.333);
    }  
    else if (i==4)
    {
        printf("Enter the value in Millibar\n");
        scanf("%f", &value);
        printf("Equals to %f Millimetre of Hg", value*.75);
    }  
    else if (i==5)
    {
        printf("Enter the value in Inch of Hg\n");
        scanf("%f", &value);
        printf("Equals to %f Bar", value*.034);
    }  
    else if (i==6)
    {
        printf("Enter the value in Bar\n");
        scanf("%f", &value);
        printf("Equals to %f Inch of Hg", value*29.53);
    }  
    else if (i==7)
    {
        printf("Enter the value in Kilopascal\n");
        scanf("%f", &value);
        printf("Equals to %f Bar", value/100);
    }  
    else if (i==8)
    {
        printf("Enter the value in Bar\n");
        scanf("%f", &value);
        printf("Equals to %f Kilopascal", value*100);
    }  
    else if (i==9)
    {
        printf("Enter the value in Standard Pressure(atm)\n");
        scanf("%f", &value);
        printf("Equals to %f Pounds/Square Inch", value*14.695);
    }  
    else if (i==10)
    {
        printf("Enter the value in Pounds/Square Inch\n");
        scanf("%f", &value);
        printf("Equals to %f Standard Pressure(atm)", value*.068);
    }  
    else if (i==11)
    {
        printf("Enter the value in Standard Pressure(atm)\n");
        scanf("%f", &value);
        printf("Equals to %f Bar", value*1.013);
    }  
    else if (i==12)
    {
        printf("Enter the value in Bar\n");
        scanf("%f", &value);
        printf("Equals to %f Standard Pressure(atm)", value*.987);
    }  
    else
    {
        printf("Invalid Option");
    }
        
    return 0;
}