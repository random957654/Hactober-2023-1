#include <iostream>
using namespace std ;
 void  quicksort(int a[ ] , int l , int h)
 {
    int temp , key low , high ;
    low = l , high = h  , key =a[(low+high)/2];
    do
    {
        while(key > a[low])
        {
          low++;
        }
         while(key > a[high])
        {
          high++;
        }
        if (low<= high)
        {
           temp = a[low];
           a[low++]= a[high];
           a[high--]=temp;
        }
    }
     while(low <= high);
     if(l <high)
      quicksort(a,l,high);
     if(low < h)
      quicksort(a,low,h);
 }
 void output(int a[] , int n)
 {
   for (int i = 0; i <= n-1; ++i)
   {
      cout << a[i];
   }
 }
 int main()
 {
    #ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
#endif
   int a[100], n , i;
   cout << "how many elements in array\n";
   cin >> n ;
   for  (i = 0 ; i < n ; i++ )
   {
      cin >> a[i] ;
   }
   quicksort(a, n);
   cout << "sorted as follows\n";
   for  (i = 0 ; i < n ; i++ )
   {
      cout << a[i] ;
      if (i < n-1)
         cout << " , " ;
   }
     cout << "\nTIME COMPLEXITY\n";
       cout << "Best === O(n)\n";
         cout << "Average === O(n²)\n";
           cout << "Worst === O(n²)\n";
            cout << "Space Complexity === O(1)\n";
 }