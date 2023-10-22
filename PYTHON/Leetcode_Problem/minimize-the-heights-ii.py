#User function Template for python3

class Solution:
    def getMinDiff(self, arr, n, k):
        arr.sort()
        ans = arr[n - 1] - arr[0]  # Maximum possible height difference
 
        tempmin = arr[0]
        tempmax = arr[n - 1]
 
        for i in range(1, n):
            if arr[i] < k:
                continue
            tempmin = min(arr[0] + k, arr[i] - k)
 
        # Minimum element when we
        # add k to whole array
        # Maximum element when we
            tempmax = max(arr[i - 1] + k, arr[n - 1] - k)
 
        # subtract k from whole array
            ans = min(ans, tempmax - tempmin)
 
        return ans
  
        
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        k = int(input())
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.getMinDiff(arr, n, k)
        print(ans)
        tc -= 1

# } Driver Code Ends
