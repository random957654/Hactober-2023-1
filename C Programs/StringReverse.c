#include <stdio.h>
#include <string.h>

int main() {
    char input[100];

    printf("Enter a string: ");
    gets(input);

    printf("Reversed string: ");
    for (int i = strlen(input) - 1; i >= 0; i--) {
        printf("%c", input[i]);
    }

    printf("\n");

    return 0;
}
