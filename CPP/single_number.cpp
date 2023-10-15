#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums) {
      int set_sum=0;
      int vector_sum=0;
      set<int> s1;
      for(int i=0;i<nums.size() ; i++)
      {   vector_sum+=nums[i];
          s1.insert(nums[i]);
      }
      for(auto it: s1)
      {
          set_sum+=it;
      }
       return (2*set_sum - vector_sum);
    }
    
    
int main()
{
    vector<int> vect;
    int x;
    cout<<"Enter the size of the vector: ";
    int n;
    cin>>n;
    for(int i=0; i<n ; i++)
    {
        cin>>x;
        vect.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<endl;
    int result = singleNumber(vect);
    if(result==0)
    {
        cout<<"There is no single element available.";
    }
    else
    {   cout<<"The single element is: ";
        cout<<result;
    }
    return 0;
}
