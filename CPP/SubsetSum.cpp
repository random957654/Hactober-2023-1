#include <bits/stdc++.h>
using namespace std;

int arr[2000][2000];

int subsetSum(int a[], int n, int sum)
{
	if (sum == 0)
		return 1;     

	if (n <= 0)
		return 0;    

	if (arr[n - 1][sum] != -1)
		return arr[n - 1][sum];


	if (a[n - 1] > sum)
		return arr[n - 1][sum] = subsetSum(a, n - 1, sum);
	else
	{
		return arr[n - 1][sum] = subsetSum(a, n - 1, sum) || subsetSum(a, n - 1, sum - a[n - 1]);
	}
}

int main()
{
	memset(arr, -1, sizeof(arr));
	int n = 5;
	int a[] = {1, 5, 3, 7, 4};
	int sum = 12;

	if (subsetSum(a, n, sum))
	{
		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;
}
