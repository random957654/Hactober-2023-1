#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9 + 7;
int n = 10;
vector<int> fac(n + 1);


int binExp(int a, int b, int m){
    int ans = 1;
    while(b){
        if(b&1) ans = (a*ans)%m;
        a = (a*a)%m;
        b >>= 1;
    }
    return ans;

}
// (a/b)%m = a%m * (b^-1)%m = a%m * pow(b, m - 2)%m 
// m is prime
int nCk(int n, int k, int m){
    // n!*(k!)^-1*(n - k)!^(-1)
    int ans = (fac[n]*binExp(fac[k], m - 2, m))%m;
    ans = (ans*binExp(fac[n - k], m - 2, m))%m;
    return ans;
}



void solve(){
    fac[0] = 1;
    for(int i = 1; i <= n; i++){
        fac[i] = (fac[i - 1]*i)%mod;
    }
    int pow = nCk(5, 2, mod);
    cout << pow << endl;
}


int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
