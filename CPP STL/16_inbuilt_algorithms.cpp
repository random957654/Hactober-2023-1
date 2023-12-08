#include <bits/stdc++.h>
using namespace std;
#define ll long long

// min_element(), max_element(), accumulate(), count(), find() and reverse() work in O(n) for arrays/vectors/strings.
// count() and  find() work in O(log n) for maps/sets.

/* nth_element description as well as code contributed by Devendra Tarak (DevT75) */

// std::nth_element() is an STL algorithm which rearranges the list in such a way such that 
// the element at the nth position is the one which should be at that position if we sort the list.
// It doesn't sort the list  just that all the elements, 
// which precede the nth element are not greater than it, and all the elements which succeed it are not less than it.
// (if std namespace can be used then nth_element else std::nth_element)

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // (1)
    int min = *min_element(v.begin(), v.end()); // min_element() returns pointer/iterator
    cout << min << endl;

    // (2)
    int max = *max_element(v.begin() + 2, v.end()); // max_element() returns pointer/iterator
    cout << max << endl;

    // (3)
    int sum = accumulate(v.begin(), v.end(), 0); // 0 is initial sum
    cout << sum << endl;

    // (4)
    int ct = count(v.begin(), v.end(), 3); // count no. of 3's
    cout << ct << endl;

    // (5)
    auto it = find(v.begin(), v.end(), 4); // find returns pointer/iterator
    if (it != v.end())
        cout << *it << endl;
    else
        cout << "Element not found" << endl;

    // (6)
    reverse(v.begin(), v.end()); // reverses original vector/string
    for (auto val : v)
    {
        cout << val << " ";
    }
    cout << endl;

    string s = "abcdefg";
    reverse(s.begin() + 2, s.end());
    cout << s << endl;

    // (7)
    int num = 4;
    cout << __builtin_popcount(num); // 2        // Printing the number of set bits (1's) in num    // O(1)

    long long num2 = 1e15;              // 10^15
    cout << __builtin_popcountll(num2); // 20   // Printing the number of set bits (1's) in num2

    // (8)
    string s = "123";
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end())); // O(n*n!)

    // The next_permutation() function takes O(N) time to find the next permutation and there are N! number of permutations for an array of size N

    int arr[] = {1, 2, 3};
    sort(arr, arr + 3);

    cout << "The 3! possible permutations with 3 elements:\n";
    do
    {
        cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
    } while (next_permutation(arr, arr + 3));

    cout << "After loop: " << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';

    /* Output :
    The 3! possible permutations with 3 elements:
        1 2 3
        1 3 2
        2 1 3
        2 3 1
        3 1 2
        3 2 1
        After loop: 1 2 3
    */

    // nth_element takes O(N) time to rearrange the list

   ll a[] = { 3,2,10,15,89,63,75 };

    // syntax : nth_element(first iterator,nth iterator,last iterator,comparator)
    // if not specified the comparator is " < ".
    // i.e. the element preceding the nth_element will be smaller and succeding elements
    // will be larger

    // using std::nth_element with n as 5

    nth_element(a,a + 4,a + 6);

    for(ll i = 0;i < 7;i++) cout << a[i] << " ";

    /*

    OUTPUT:

        15  2  10  3  63  89  75
        ------------  nth ******
        all the elements preceding the 5th element(63) are smaller while succeding elements are greater


    
    */
    // nth_element gets sorted through this.   
    // custom comparator may be used as well.

    return 0;
}