#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    vector<int> curr(2), prev(2);
    prev[0] = prev[1] = nums[0];
    for (int i = 1; i < size(nums); i++)
    {
        curr[1] = max(nums[i], nums[i] + prev[1]);
        curr[0] = max(prev[0], curr[1]);
        prev = curr;
    }
    return prev[0];
}

int main()
{
    vector<int> arr = {1, 2, 3, -7, 9, 2, -8};
    int max_sum = maxSubArray(arr);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}
