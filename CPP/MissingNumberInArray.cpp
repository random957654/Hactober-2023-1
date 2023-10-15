#include <iostream>
#include <vector>

int findMissingNumber(std::vector<int>& arr) {
    int n = arr.size();
    // Calculate the sum of all numbers from 1 to n+1 (including the missing number)
    int expectedSum = (n + 1) * (n + 2) / 2;
    
    // Calculate the actual sum of the elements in the array
    int actualSum = 0;
    for (int num : arr) {
        actualSum += num;
    }
    
    // The missing number is the difference between the expected and actual sums
    int missingNumber = expectedSum - actualSum;
    
    return missingNumber;
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " elements in the range 1 to " << n + 1 << " (one element is missing):" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int missingNumber = findMissingNumber(arr);
    std::cout << "The missing number in the array is: " << missingNumber << std::endl;

    return 0;
}
