#include <iostream>
#include <vector>

class Solution {
public:
    void solve(int s, int& n, int k, std::vector<int>& tmp, std::vector<std::vector<int>>& ans) {
        if (k == 0) {
            ans.push_back(tmp);
            return;
        }
        for (int i = s; i <= n; i++) {
            tmp.push_back(i);
            solve(i + 1, n, k - 1, tmp, ans);
            tmp.pop_back();
        }
    }

    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> ans;
        std::vector<int> tmp;
        solve(1, n, k, tmp, ans);
        return ans;
    }
};

int main() {
    Solution solution;
    int n = 4;  // Change this to the desired value of 'n'
    int k = 2;  // Change this to the desired value of 'k'

    std::vector<std::vector<int>> combinations = solution.combine(n, k);

    std::cout << "Combinations of " << k << " numbers from 1 to " << n << ":" << std::endl;
    for (const std::vector<int>& combination : combinations) {
        for (int num : combination) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}