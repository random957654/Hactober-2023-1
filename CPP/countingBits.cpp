/*Problem Statement: Counting Bits

Problem Description:
Given a non-negative integer num, for every number i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return it as an array.

Example:
Input: num = 5
Output: [0, 1, 1, 2, 1, 2]

Explanation:

0 is represented as 0 in binary, which has 0 number of 1's.
1 is represented as 1 in binary, which has 1 number of 1.
2 is represented as 10 in binary, which has 1 number of 1.
3 is represented as 11 in binary, which has 2 number of 1's.
4 is represented as 100 in binary, which has 1 number of 1.
5 is represented as 101 in binary, which has 2 number of 1's.

C++ Solution:
*/

#include <iostream.h>
#include <vector>

class Solution {
public:
    std::vector<int> countBits(int num) {
        std::vector<int> result(num + 1, 0);
        for (int i = 1; i <= num; ++i) {
            // To count number of 1's in i, we can use (i & (i - 1)) + 1
            // It counts number of 1's in (i - 1) and adds 1 to the count
            result[i] = result[i & (i - 1)] + 1;
        }
        return result;
    }
};
