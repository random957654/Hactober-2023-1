#include <stdio.h>
#include <string.h>

// Function to check if two strings are anagrams
int areAnagrams(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // If the lengths of the strings are not the same, they cannot be anagrams
    if (len1 != len2) {
        return 0;
    }

    // Initialize an array to store the count of each character
    int count[256] = {0};

    // Count the occurrences of characters in the first string
    for (int i = 0; i < len1; i++) {
        count[(int)str1[i]]++;
    }

    // Decrement the count for each character in the second string
    for (int i = 0; i < len2; i++) {
        count[(int)str2[i]]--;
    }

    // If the strings are anagrams, all elements in the count array should be zero
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str1[100], str2[100];

    // Input the two strings from the user
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    if (areAnagrams(str1, str2)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }

    return 0;
}
