#include <iostream>
using namespace std ;
 int  bubblesort(int a[ ] , int n )
 {
    int i , j ,  temp;
    for  (i = 0 ; i < n ; i++ ) // iterating every element 
   {
           for  (j = 0 ; j < n - i - 1 ; j++ )
            //with evry iteration of i the upper limit of j decreasing 
            //so it can do not iterate thw iterated element 
        {
           if (a[j]  > a[j + 1]) // the condition which decide the replacabilty of element 
           { 
           temp = a[j];
           a[j] =  a[j+1];
             a[j+1] =  temp ;
           }
        }
   }
   return 0;
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
   bubblesort(a, n);
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