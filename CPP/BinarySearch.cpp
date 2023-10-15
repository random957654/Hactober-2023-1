#include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int s, int e, int key) {
   //base case
    if(s>e)
    return false;

    int mid = s+ (e-s)/2;

    if (arr[mid] == k)
    return true;

    if(arr[mid]>k){
        binarySearch(arr, s, mid-1, k);
    }
    else{
        binarySearch(arr, mid+1, e, k);
    }
}

int main() {
  int n;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int key;
  cin >> key;

  cout << binarySearch(arr, n, key) << endl;

  return 0;
}
