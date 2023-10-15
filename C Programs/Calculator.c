#include <stdio.h>

int main() {
    char op;
    float num1, num2;

    printf("Enter operator either + or - or * or /: ");
    scanf("%c", &op);

    printf("Enter two operands: ");
    scanf("%f %f", &num1, &num2);

    switch(op) {
        case '+':
            printf("%.2f", num1+num2);
            break;

        case '-':
            printf("%.2f", num1-num2);
            break;

        case '*':
            printf("%.2f", num1*num2);
            break;

        case '/':
            if(num2 == 0) {
                printf("Error: Division by zero");
            } else {
                printf("%.2f", num1/num2);
            }
            break;

        default:
            printf("Error: Invalid operator");
            break;
    }

    return 0;
}
