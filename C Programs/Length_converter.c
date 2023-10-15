#include <stdio.h>

int main() {
    int i;
    float value;

    printf("Enter The No. of conversion you want\n");
    printf("1. Kilometre to Metre\n");
    printf("2. Metre to Kilometre\n");
    printf("3. Metre to Centimetre\n");
    printf("4. Centimetre to Metre\n");
    printf("5. Kilometre to Centimetre\n");
    printf("6. Centimetre to Metre\n");
    printf("7. Centimetre to Milimetre\n");
    printf("8. Milimetre to Centimetre\n");
    printf("9. Foot to Inch\n");
    printf("10. Inch to Foot\n");
    printf("11. Inch to Centimetre\n");
    printf("12. Centimetre to Inch\n\n");

    scanf("%d", &i);

    if (i==1)
    {
        printf("Enter the value in Kilometre\n");
        scanf("%f", &value);
        printf("Equals to %f metre", value*1000);
    } 
    else if (i==2)
    {
        printf("Enter the value in metre\n");
        scanf("%f", &value);
        printf("Equals to %f kilometre", value/1000);
    }  
    else if (i==3)
    {
        printf("Enter the value in metre\n");
        scanf("%f", &value);
        printf("Equals to %f centimetre", value*100);
    }  
    else if (i==4)
    {
        printf("Enter the value in centimetre\n");
        scanf("%f", &value);
        printf("Equals to %f metre", value/100);
    }  
    else if (i==5)
    {
        printf("Enter the value in kilometre\n");
        scanf("%f", &value);
        printf("Equals to %f centimetre", value*100000);
    }  
    else if (i==6)
    {
        printf("Enter the value in centimetre\n");
        scanf("%f", &value);
        printf("Equals to %f kilometre", value/100000);
    }  
    else if (i==7)
    {
        printf("Enter the value in centimetre\n");
        scanf("%f", &value);
        printf("Equals to %f milimetre", value*10);
    }  
    else if (i==8)
    {
        printf("Enter the value in milimetre\n");
        scanf("%f", &value);
        printf("Equals to %f centimetre", value/10);
    }  
    else if (i==9)
    {
        printf("Enter the value in Foot\n");
        scanf("%f", &value);
        printf("Equals to %f Inch", value*12);
    }  
    else if (i==10)
    {
        printf("Enter the value in Inch\n");
        scanf("%f", &value);
        printf("Equals to %f Foot", value/12);
    }  
    else if (i==11)
    {
        printf("Enter the value in Inch\n");
        scanf("%f", &value);
        printf("Equals to %f centimetre", value*2.54);
    }  
    else if (i==2)
    {
        printf("Enter the value in centimetre\n");
        scanf("%f", &value);
        printf("Equals to %f Inch", value*.394);
    }  
      
    
    
    return 0;
}