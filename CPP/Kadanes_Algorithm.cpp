/*
  Lets take the example: {-2, -3, 4, -1, -2, 1, 5, -3}

  To find largest subarray sum/ Max contiguous array sum : 7 (4 + -1 + -2 + 1 + 5)
*/

#include <bits/stdc++.h>
using namespace std;

// Kadane's Algortihm is used to find max contiguous subarray sum within 1-D array
// The idea is to look for sum of all contiguous subarray unless and until the sum becomes less than 0
int KadanesAlgo(int arr[], int n)
{
    int sum = 0;
    int maxSum = INT_MIN; // This is important is order to find max sum when all integers are negative

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        // It is important to update maxSum everytime after every iteration
        maxSum = max(sum, maxSum);

        // NOTE: if sum < 0, we will reset the sum to 0
        if (sum < 0)
            sum = 0;
    }

    return maxSum;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum = KadanesAlgo(a, n);

    cout << max_sum;
    return 0;
}