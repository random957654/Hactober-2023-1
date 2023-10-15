#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Element found at index 'mid'
        }
        else if (arr[mid] < target) {
            left = mid + 1; // Target is in the right half
        }
        else {
            right = mid - 1; // Target is in the left half
        }
    }

    return -1; // Element not found
}

int main() {
    std::vector<int> sortedArray;
    int n;
    
    // Input the size of the array
    std::cout << "Enter the size of the sorted array: ";
    std::cin >> n;
    
    // Input the elements of the sorted array
    std::cout << "Enter the elements of the sorted array in ascending order:" << std::endl;
    for (int i = 0; i < n; ++i) {
        int element;
        std::cin >> element;
        sortedArray.push_back(element);
    }

    int target;
    std::cout << "Enter the target element to search for: ";
    std::cin >> target;

    int result = binarySearch(sortedArray, target);

    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}
