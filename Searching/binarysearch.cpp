#include <iostream>
#include <vector>

// Binary Search Recursive
// Contributed by Devendra Tarak (DevT75)

int binarySearchRecursive(const std::vector<int>& arr, int left, int right, int target){
    if(left >= right){
        int mid = left + (right - left) >> 1;
        // if the target is found at mid index
        if(arr[mid] == target) return mid;
        // else if mid is greater then target implies our requied is in the first half of array
        else if(arr[mid] > target) return binarySearchRecursive(arr,left,mid - 1,target);
        // else the required element is presented in second half
        else return binarySearchRecursive(arr,mid + 1,right,target);
    }
    // we will reach this if we could not find the target element so return -1
    return -1;
}


int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid;
        }
        
        // If the target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        } 
        // If the target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }
    
    // Target not found in the array
    return -1;
}

int main() {
    std::vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 10;
    int result = binarySearch(arr, target);
    
    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }
    
    return 0;
}