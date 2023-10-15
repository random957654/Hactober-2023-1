#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int m = low + (high - low) / 2;

        if (arr[m] == target)
            return m;

        if (arr[m] < target)
            low = m + 1;

        else
            high = m - 1;
    }

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
