#include<bits/stdc++.h>
using namespace std;

class Solution
{  
    public:
    // Single array sapce optimization: 
    // TC->O(N*maxWeight) | SC->O(maxWeight) 
    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
    {
        vector<int> curr(maxWeight+1, 0);

        for(int i = weight[0]; i <= maxWeight; i++)
            curr[i] = value[0];
        
        for(int idx = 1; idx < n; idx++)
        {
            for(int wt = maxWeight; wt >= 0; wt--)
            {
                int not_take = 0 + curr[wt];
                int take = INT_MIN;
                if(weight[idx] <= wt) 
                    take = value[idx] + curr[wt-weight[idx]];

                curr[wt] = max(take, not_take);
            }
        }
        return curr[maxWeight];
    }
};
int main()
 {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        vector<int> wt(n);
        vector<int> val(n);
        
        //inserting the values
        for(int i = 0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapsack(wt, val, n, w)<<endl;
        
        return 0;
} 
