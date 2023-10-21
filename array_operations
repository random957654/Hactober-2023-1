#include <iostream>

// Function to initialize an array with values
void initializeArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1; // Initialize with values 1, 2, 3, ...
    }
}

// Function to insert an element at a specific position in the array
void insertElement(int arr[], int& size, int element, int position) {
    if (position < 0 || position > size) {
        std::cout << "Invalid position for insertion." << std::endl;
        return;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
}

// Function to delete an element from a specific position in the array
void deleteElement(int arr[], int& size, int position) {
    if (position < 0 || position >= size) {
        std::cout << "Invalid position for deletion." << std::endl;
        return;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

// Function to search for an element in the array and return its position
int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i; // Element found at position i
        }
    }
    return -1; // Element not found
}

// Function to print the elements of the array
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int maxSize = 100;
    int arr[maxSize];
    int size = 0;

    // Initialize the array
    initializeArray(arr, size);

    std::cout << "Original Array: ";
    printArray(arr, size);

    // Insert an element at a specific position
    int elementToInsert = 42;
    int insertPosition = 3;
    insertElement(arr, size, elementToInsert, insertPosition);

    std::cout << "Array after insertion: ";
    printArray(arr, size);

    // Delete an element from a specific position
    int deletePosition = 2;
    deleteElement(arr, size, deletePosition);

    std::cout << "Array after deletion: ";
    printArray(arr, size);

    // Search for an element
    int elementToSearch = 5;
    int searchResult = searchElement(arr, size, elementToSearch);
    if (searchResult != -1) {
        std::cout << "Element " << elementToSearch << " found at position " << searchResult << std::endl;
    } else {
        std::cout << "Element " << elementToSearch << " not found in the array." << std::endl;
    }

    return 0;
}
