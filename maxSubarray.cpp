
#include <iostream>
using namespace std;

// function for kadane's algorithm
static void kadane(int Array[], int n) {
  int max_sum = 0;
  int current_sum = 0;

  int max_start = 0;
  int max_end = 0;
  int current_start = 0;
  int current_end = 0;

  for(int i=0; i<n; i++) {
    current_sum = current_sum + Array[i];
    current_end = i;

    if (current_sum < 0) {
      current_sum = 0;
      //Start a new sequence from next element
      current_start = current_end + 1;
    }

    if(max_sum < current_sum) {
      max_sum = current_sum;
      max_start = current_start;
      max_end = current_end;
    }
  }
  
  cout<<"Maximum SubArray is: "<<max_sum<<"\n";
  cout<<"Start index of max_Sum: "<<max_start<<"\n";
  cout<<"End index of max_Sum: "<<max_end<<"\n";
}

// test the code
int main() {
  int MyArray[] = {-3, 1, -8, 12, 0, -3, 5, -9, 4};
  int n = sizeof(MyArray) / sizeof(MyArray[0]);
  kadane(MyArray, n);
  return 0;
}
