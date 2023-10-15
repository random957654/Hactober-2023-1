#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define MOD 1000000007
#define loop(i,n)        for(ll i=0;i<n;i++)
#define input_arr(a,n)   for(ll i=0;i<n;i++){cin>>a[i];}
#define output_arr(a,n)  for(ll i=0;i<n;i++){cout<<a[i]<<" ";}
#define input_vec(v)     for(auto &x: v) cin>>x;
#define output_vec(v)    for(auto &x: v) cout<<x<<" ";
#define fast_io          ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){

}

int main()
{
    fast_io;
    int test;
    cin >> test;
    while (test--)
    {
float a,b,c;
cin>>a>>b>>c;
float diff=abs(a-b);
float ans=ceil(diff/(2*c));
cout<<ans<<endl;

    }

    return 0;
}


 
