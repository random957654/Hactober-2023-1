class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;

        Arrays.sort(nums);

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int l = j + 1;
                int k = n - 1;

                while (l < k) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[k];

                    if (sum == target) {
                        ans.add(Arrays.asList(nums[i], nums[j], nums[l], nums[k]));

                        while (l < k && nums[l] == nums[l + 1]) {
                            l++;
                        }
                        while (l < k && nums[k] == nums[k - 1]) {
                            k--;
                        }
                        l++;
                        k--;
                    } else if (sum < target) {
                        l++;
                    } else {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
}
