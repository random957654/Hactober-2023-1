#include <iostream>
#include <cmath>

int main()
{
    int n1;
    std::cin >> n1;
    int num = n1;
    int n = 0;

    while (num != 0)
    {
        num /= 10;
        ++n;
    }

    num = n1;
    int sum = 0;
    while (num != 0)
    {
        int d = num % 10;
        sum += std::pow(d, n);
        num /= 10;
    }

    std::cout << (n1 == sum);

    return 0;
}
