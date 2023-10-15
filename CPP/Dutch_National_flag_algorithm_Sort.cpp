//Dutch National Flag sorting algorithm
#include <bits/stdc++.h> 
using namespace std;
int main()
{
    int n;
   cout<<"Enter the size of array ";
   cin>>n;
   int a[n];
   //taking input
   cout<<"Enter the elements ";
   for(int i=0;i<n;i++)
   {
    cin>>a[i];
   }

//sorting algorithm
   int low=0,mid=0,high=n-1;
   while(mid<=high)
   {
        if(a[mid]==0)
        {
            swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else if(a[mid]==1)
        {
            mid++;
        }
        else if(a[mid]==2)
        {
            swap(a[mid],a[high]);
            high--;
        }
   }
   
   //printing result
   cout<<"\nFinal sorted array is ";
   for(int i=0;i<n;i++)
   {
    cout<<a[i]<<" ";
   }


}