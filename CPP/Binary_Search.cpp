// C++ program to implement recursive Binary Search

#include<iostream>
using namespace std;

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
class Solution {
    public:
    int searchsortedarray(int arr[],int n,int k)
    {
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid =(low+high)/2;

            // If the element is present at the middle
            // itself
            if(arr[mid]==k)
                return 1;

             // If element is smaller than mid, then
            // it can only be present in left subarray
            else if(arr[mid]>k)
                high=mid-1;

            // Else the element can only be present
            // in right subarray
            else
                low=mid+1;
        }
        return -1;
    }
};

int main()
{
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<size;i++)
        cin>>arr[i];
    int target;
    cout<<"Enter the element to be searched: ";
    cin>>target;
    Solution ans;
    int val=ans.searchsortedarray(arr,size,target);
    if(val>0)
    {
        cout<<"The element is present  ";
    }
    else 
        cout<<"Element is not found";
    return 0;
}
