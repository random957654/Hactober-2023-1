#include <stdio.h>
#include <string.h>
int main()
{
    char word[100];
    printf("ENTER A WORD TO FIND WHETHER IT IS A PALINDROME OR NOT\n\n");
    gets(word);
    printf("\nTHE REVERSED WORD IS %s\n\n", strrev(word));

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == word[strlen(word) - i - 1])
        {
            if (i == strlen(word) - 1)
            {
                printf("YES, IT IS A PALINDROME.\n");
                break;
            }
            else
            {
                continue;
            }
        }
        else
        {
            printf("NO, IT IS NOT A PALINDROME.\n");
            break;
        }
    }
    return 0;
}
