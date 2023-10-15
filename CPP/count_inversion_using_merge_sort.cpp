#include <bits/stdc++.h> 

int merge(vector<int> &arr, vector<int> &temp, int start, int end){
	int cnt=0;
	int mid = start + (end-start)/2;
	int i=start, j=mid+1;
	int k=start;
	while(i<=mid && j<=end){
		if(arr[i]<=arr[j]){
			temp[k++] = arr[i++];
		}else{
			cnt += mid-i+1;
			temp[k++] = arr[j++];
		}
	}
	while(i<=mid) temp[k++] = arr[i++];
	while(j<=end) temp[k++] = arr[j++];

	for(int i=start; i<=end; i++) arr[i] = temp[i];
	return cnt;
}

int count_inversion(vector<int> &v, vector<int> &temp, int start, int end){
	int cnt=0;
	if(start<end){
		int mid = start + (end-start)/2;
		cnt += count_inversion(v, temp, start, mid);
		cnt += count_inversion(v, temp, mid+1, end);
		cnt += merge(v, temp, start, end);
	}
	return cnt;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    long long temp[n];
    return count_inversion(arr, temp, 0, n-1)
}
