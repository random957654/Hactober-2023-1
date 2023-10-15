#include <iostream>
#include <vector>

void flip(std::vector<int>& arr, int i) {
    int start = 0;
    while (start < i) {
        std::swap(arr[start], arr[i]);
        start++;
        i--;
    }
}

int findMaxIndex(std::vector<int>& arr, int n) {
    int maxIndex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void pancakeSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int currSize = n; currSize > 1; currSize--) {
        int maxIndex = findMaxIndex(arr, currSize);

        if (maxIndex != currSize - 1) {
            
            if (maxIndex != 0) {
                flip(arr, maxIndex);
            }

            flip(arr, currSize - 1);
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> arr(n);

    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    pancakeSort(arr);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
