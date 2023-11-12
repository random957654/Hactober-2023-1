#include <stdio.h>

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Fibonacci search function
int fibonacciSearch(int arr[], int n, int key) {
    int fibM2 = 0; // (m-2)th Fibonacci number
    int fibM1 = 1; // (m-1)th Fibonacci number
    int fib = fibM2 + fibM1; // mth Fibonacci number

    // Find the smallest Fibonacci number greater than or equal to n
    while (fib < n) {
        fibM2 = fibM1;
        fibM1 = fib;
        fib = fibM2 + fibM1;
    }

    int offset = -1; // To keep track of the eliminated range
    while (fib > 1) {
        int i = min(offset + fibM2, n - 1);

        // If the key is greater than the value at index i, cut the subarray from offset to i
        if (arr[i] < key) {
            fib = fibM1;
            fibM1 = fibM2;
            fibM2 = fib - fibM1;
            offset = i;
        }
        // If the key is less than the value at index i, cut the subarray after i + 1
        else if (arr[i] > key) {
            fib = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fib - fibM1;
        }
        // Key is found
        else
            return i;
    }

    // Compare the key with the last element
    if (fibM1 && arr[offset + 1] == key)
        return offset + 1;

    // Key is not found
    return -1;
}

int main() {
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 85;

    int result = fibonacciSearch(arr, n, key);

    if (result == -1)
        printf("Element %d is not found in the array.\n", key);
    else
        printf("Element %d is found at index %d.\n", key, result);

    return 0;
}
