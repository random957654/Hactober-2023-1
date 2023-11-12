#include <bits/stdc++.h>

using namespace std;

 int search(vector<int>& nums, int target) {

        int i=0; 
        if(nums.size()==1 && nums[i]==target){
            return i;
        }
        int j=nums.size()-1;
        while(i<=j){
            if(nums[i]==target){
                return i;
            }else{
                i++;
            }
            if(nums[j]==target){
                return j;
            }else{
                j--;
            }
        }
        return -1;
    }
int main()
{
   int t;cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       int target;
       cin>>target;
       int a;
    vector<int> v;//taking user input for the array
    for(int i=0 ; i<n ; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    int ans = search(v,target);
    cout<<ans<<endl;
   }

    return 0;
}
