class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        global_max = -sys.maxsize-1
        local_max = 0

        for i in range(len(nums)):
            local_max += nums[i]

            if local_max > global_max:
                global_max = local_max
            
            if local_max < 0:
                local_max = 0
        return global_max
        
