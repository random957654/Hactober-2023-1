#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int num1, num2, num3;

  cout << "Enter three numbers: ";
  cin >> num1 >> num2 >> num3;

  int height = std::max(num1, std::max(num2, num3));

  cout << "The height number is: " << height << endl;

  return 0;
}
