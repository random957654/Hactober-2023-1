#include <iostream> 
using namespace std; 

int main() 
{ 
	cout<<"Enter the siez of array ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements "; 
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

	for (int gap = n/2; gap > 0; gap = gap/2) 
	{ 
		for (int i = gap; i < n; i += 1) 
		{  
			int temp = arr[i]; 
			int j;			 
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
				arr[j] = arr[j - gap];
			arr[j] = temp; 
		} 
	} 

	cout << "\nSorted array \n"; 
		for (int i=0; i<n; i++) 
		cout << arr[i] << " "; 


	return 0; 
} 
