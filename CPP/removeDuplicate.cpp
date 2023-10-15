#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[k - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 1, 2, 2, 2, 3, 4, 4, 5, 5, 5};

    std::cout << "Original array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int newLength = solution.removeDuplicates(nums);

    std::cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "New length of the array: " << newLength << std::endl;

    return 0;
}