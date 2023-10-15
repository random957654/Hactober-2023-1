#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define MOD 1000000007
#define loop(i,n)        for(ll i=1;i<=n;i++)
#define input_arr(a,n)   for(ll i=0;i<n;i++){cin>>a[i];}
#define output_arr(a,n)  for(ll i=0;i<n;i++){cout<<a[i]<<" ";}
#define input_vec(v)     for(auto &x: v) cin>>x;
#define output_vec(v)    for(auto &x: v) cout<<x<<" ";
#define fast_io          ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(a)         cout<<a<<endl;
void solve(){
    ll n,k,x;
       cin>>n>>k>>x;
 ll sumn=n*(n+1)/2;
       ll sumkl=sumn-(n-k)*(n-k+1)/2;
       ll sumk=k*(k+1)/2;
       if(x>=sumk&&x<=sumkl){
        cout<<"YES"<<endl;
       }
       else{
cout<<"NO"<<endl;
       }
}
int main()
{
    fast_io;
    int test;
    cin >> test;
    while (test--)
    {
      solve();
    }

    return 0;
}


 
