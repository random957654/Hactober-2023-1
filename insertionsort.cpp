#include <iostream>
using namespace std ;
void insertionsort(int a [] , int n )
{
    int temp , j ;
  for (int k = 0; k < n; ++k)//iterating the array for all elements
  {
   temp = a[k];//storing temporary data into a var 
   j=k-1;
   while((temp < a[j]) && (j>=0))//iterating the array for sorting (inner sort)
   {
      a[j+1]=a[j];
      j=j-1;
   }
   a[j+1]=temp;//replacing the original var from temp
  }

}
int main()
 {
    #ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
#endif
   int a[100], n , i ;
   cout << "how many elements in array\n";
   cin >> n ;
   for  (i = 0 ; i < n ; i++ )
   {
      cin >> a[i] ;
   }
      for  (i = 0 ; i < n ; i++ )
   {
      cout << a[i] ;
   }

   insertionsort(a,n);


   cout << endl ;
         for  (i = 0 ; i < n ; i++ )
   {
      cout << a[i] ;
   }
    cout << "\nTIME COMPLEXITY\n";
       cout << "Best === O(n)\n";
         cout << "Average === O(n²)\n";
           cout << "Worst === O(n²)\n";
            cout << "Space Complexity === O(1)\n";
}