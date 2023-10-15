#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin>>n;
    vector<vector<int>>a;
    map<int,vector<int>>m;
    unordered_set<int>us;
    for(int i=0;i<n;i++){
        int size ; cin>>size;
        vector<int>temp;
        for(int j =0;j<size;j++){
           int x; cin>>x;
           us.insert(x);
           m[x].push_back(i);
           temp.push_back(x);
        }
        a.push_back(temp);
    }
int ans = 0;
  for(auto &it:us){
    int val = it;
    unordered_set<int>st;
    for(int i=0;i<n;i++){
      if(find(m[val].begin(),m[val].end(),i)!=m[val].end()){
        continue;
      } 
      else{
         for(auto itr:a[i]){
            st.insert(itr);
         }
      }
    }
    if(st.size()!=us.size()){
        int val = st.size();
        ans = max(ans,val);
    }
  }


cout<<ans<<endl;
     

}
int main(){

    int t; cin>>t;
    while(t--){
        solve();
    }


    return 0;
}