#include <bits/stdc++.h>  
void Shell_sort(int Array[], int N) {
    int gap, j, i, Temp;  // Declare variables for the shell sort algorithm.
    
    // Start with a large gap and reduce it in each iteration.
    for (gap = N/2; gap > 0; gap = gap/2) {
        for (i = gap; i < N; i++) {
            Temp = Array[i];  // Store the current element to be compared and moved.
            
            // Compare and move elements within the gap distance.
            for (j = i; j >= gap && Array[j - gap] > Temp; j = j - gap) {
                Array[j] = Array[j - gap];
            }
            Array[j] = Temp;  // Place the stored element in its correct position.
        }
    }
}

void Display_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i];  // Display the elements of the array.
    cout << endl;  // Print a newline after displaying the array.
}

int main() {
    int array[] = {21, 12, 14, 46, 7, 25, 10, 62, 19, 31, 1};  // Initialize an array.
    int size = sizeof(array) / sizeof(int);  // Calculate the size of the array.
    
    Shell_sort(array, size);  // Call the Shell Sort function to sort the array.
    
    cout << "Sorted array is: \n";  // Display a message indicating the sorted array.
    Display_array(array, size);  // Display the sorted array.
    
    return 0;  // Return 0 to indicate successful execution of the program.
}
