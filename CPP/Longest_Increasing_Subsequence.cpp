/* 
 Given an array arr[] of size N, the task is to find the length of the Longest Increasing Subsequence (LIS) i.e., the longest possible subsequence in which the elements of the subsequence are sorted in increasing order.
 */

/*
Example:
1.
Input: arr[] = {3, 10, 2, 1, 20}
Output: 3
Explanation: The longest increasing subsequence is 3, 10, 20

Input: arr[] = {3, 2}
Output:1
Explanation: The longest increasing subsequences are {3} and {2}

2.
Input: arr[] = {50, 3, 10, 7, 40, 80}
Output: 4
Explanation: The longest increasing subsequence is {3, 7, 40, 80}

*/

// Dynamic Programming C++ implementation
// of LIS problem
#include <bits/stdc++.h>
using namespace std;

// lis() returns the length of the longest
// increasing subsequence in arr[] of size n
int lis(int arr[], int n)
{
	int lis[n];

	lis[0] = 1;

	// Compute optimized LIS values in
	// bottom up manner
	for (int i = 1; i < n; i++) {
		lis[i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
	}

	// Return maximum value in lis[]
	return *max_element(lis, lis + n);
}

// Driver program to test above function
int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	printf("Length of lis is %d\n", lis(arr, n));
	return 0;
}


