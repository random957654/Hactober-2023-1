#include <iostream>

using namespace std;

int sum(int x, int y)
        {
            return x == y ? (x + y)*3 : x + y;
        }
        
        
int main() 
 {
  cout << sum(1, 2) << endl;  
  cout << sum(3, 2) << endl;  
  cout << sum(2, 2) << endl;  
  return 0;    
}