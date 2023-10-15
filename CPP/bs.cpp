// #include <bits/stdc++.h>
// using namespace std;
// int* bubbleSort(int arr[], int n) {

  
//   for (int i = 0; i< n; i++) {
      
    
//     for (int j = 0; j < n -1- i; j++) {

    
//       if (arr[j] > arr[j + 1]) {
//         int temp = arr[j];
//         arr[j] = arr[j+ 1];
//         arr[j + 1] = temp;
//       }
//     }
//   }
//   return arr;
// }

// int binarySearch(int arr[], int x, int low, int high) {
  
	
//   while (low <= high) {
//     int mid = low + high / 2;

//     if (arr[mid] == x)
//       return mid;

//     if (arr[mid] < x)
//       low = mid + 1;

//     else
//       high = mid - 1;
//   }

//   return -1;
// }

// int main() {
//   int n,x;
// 	cout<<"Enter the size of the array"<<endl;
// 	cin>>n;
// 	int arr[n];
//     cout<<"Enter the elements of the array"<<endl;    
// 	for(int i=0;i<n;i++)
// 	cin>>arr[i];
// 	cout<<"Enter the element you want to search in the array"<<endl;
// 	cin>>x;
//     bubbleSort(arr,n);
//   int result = binarySearch(arr, x, 0, n-1 );
//   if (result == -1)
//     printf("Not found");
//   else
//     printf("Element is found at index %d", result);
// }
#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n) {

  
  for (int i = 0; i< n; i++) {
    for (int j = 0; j < n -1- i; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j+ 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int binarySearch(int arr[], int x, int low, int high) {
  while (low <= high) {
    int mid = low + high / 2;

    if (arr[mid] == x)
      return mid;

    if (arr[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main() {
  int n,x;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array"<<endl;    
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"Enter the element you want to search in the array"<<endl;
    cin>>x;

    bubbleSort(arr,n);
  int result = binarySearch(arr, x, 0, n-1 );
  if (result == -1)
    printf("Element is not present in the array");
  else
    printf("Element is found at position %d", result +1);
}
