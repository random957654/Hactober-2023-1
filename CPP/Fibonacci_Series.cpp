#include <iostream>
using namespace std;

int main()
{
    int n;
    // enter the number of elements to be printed.
    cout << "enter the number of elements: ";
    cin >> n;
 
    int x = 0,y = 1;
    // while loop will run till we have printed the required number of elements of the series.
    while(n--){
        cout << y << ' ';
        x += y;
        swap(x,y);
    }
}
