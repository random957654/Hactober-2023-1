#include <bits/stdc++.h>
using namespace std;

int subArraySum(int arr[], int n, int sum)
{
    int currentSum = arr[0], start = 0, i;
 
    for (i = 1; i <= n; i++) {
        while (currentSum > sum && start < i - 1) {
            currentSum = currentSum - arr[start];
            start++;
        }
        
        if (currentSum == sum) {
            cout << "Between indexes " << start
                 << " and " << i - 1;
            return 1;
        }
        if (i < n)
            currentSum = currentSum + arr[i];
    }
    cout << "No subarray found";
    return 0;
}
 
// Driver Code
int main()
{
    int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 23;
    subArraySum(arr, n, sum);
    return 0;
}