class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) {
            return true;
        }

        long long left = 1;
        long long right = num;

        while (left <= right) {
            long long mid = left + ((right - left) >> 1);
            long long square = mid * mid;

            if (square == num) {
                return true;
            } else if (square < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};