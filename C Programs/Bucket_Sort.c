#include <stdio.h>
#include <stdlib.h>


int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void bucketSort(int arr[], int n) {
    int max = findMax(arr, n);
    int bucket[max + 1];

    
    for (int i = 0; i <= max; i++) {
        bucket[i] = 0;
    }


    for (int i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    int i = 0;
    for (int j = 0; j <= max; j++) {
        while (bucket[j] > 0) {
            arr[i] = j;
            i++;
            bucket[j]--;
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
