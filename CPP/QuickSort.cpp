#include <iostream>
using namespace std;

int partition(int* arr, int start, int end)
{
	// assuming last element as pivotElement
	int index = 0, pivotElement = arr[end], pivotIndex;
	int* temp = new int[end - start + 1]; // making an array whose size is equal to current partition range...
	for (int i = start; i <= end; i++) // pushing all the elements in temp which are smaller than pivotElement
	{
		if(arr[i] < pivotElement)
		{
			temp[index] = arr[i];
			index++;
		}
	}

	temp[index] = pivotElement; // pushing pivotElement in temp
	index++;

	for (int i = start; i < end; i++) // pushing all the elements in temp which are greater than pivotElement
	{
		if(arr[i] > pivotElement)
		{
			temp[index] = arr[i];
			index++;
		}
	}
// all the elements now in temp array are order :
// leftmost elements are lesser than pivotElement and rightmost elements are greater than pivotElement
			
	
	
	index = 0;
	for (int i = start; i <= end; i++) // copying all the elements to original array i.e arr
	{
		if(arr[i] == pivotElement)
		{
			// for getting pivot index in the original array.
			// we need the pivotIndex value in the original and not in the temp array
			pivotIndex = i;
		}
		arr[i] = temp[index];
		index++;
	}
	return pivotIndex; // returning pivotIndex
}

void quickSort(int* arr, int start, int end)
{
	if(start < end)
	{
		int partitionIndex = partition(arr, start, end); // for getting partition
		quickSort(arr, start, partitionIndex - 1); // sorting left side array
		quickSort(arr, partitionIndex + 1, end); // sorting right side array
	}
	return;
}

int main()
{
	int size = 9;
	int arr[size] = {5, 12, 7, 1, 13, 2 ,23, 11, 18};
	
	cout << "Unsorted array : ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	printf("\n");

	quickSort(arr, 0, size - 1);
	
	cout << "Sorted array : ";
	for (int i = 0; i < size; i++)
	{
	cout << arr[i] << " ";
	}

	return 0;
}
