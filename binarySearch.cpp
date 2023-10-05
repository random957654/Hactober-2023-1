// C++ program to implement iterative Binary Search
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int m = low + (high - low) / 2;

        // Check if x is present at mid
        if (arr[m] == target)
            return m;

        // If x greater, ignore left half
        if (arr[m] < target)
            low = m + 1;

        // If x is smaller, ignore right half
        else
            high = m - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

int main()
{
    vector<int> arr = {2, 3, 4, 10, 40};
    int target = 1;
    int result = binarySearch(arr, target);

    if (result == -1)
        cout << "Element is not present in array";
    else
        cout << "Element is present at index: " << result;
    return 0;
}
