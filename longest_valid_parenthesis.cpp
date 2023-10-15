#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#define ll long long
#define ld long double
#define int ll

const ll mod=1000000007;
const ll inf = 1e18; 
const ll mod2=998244353;
const ld pi = 3.14159265358979323846;

#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define ppb pop_back
#define ins insert
#define pll pair<ll,ll>
#define ff first
#define ss second
#define fr0(va,st) for(int va=0;va<st;va++)
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vector<int>>
#define all(xxx90) (xxx90).begin(),(xxx90).end()
#define allr(xxx90) (xxx90).rbegin(),(xxx90).rend()
#define umap unordered_map
#define mset multiset
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template<class T> void fin(vector<T> &v){ int n=v.size(); for(int i=0; i<n; i++) cin>>v[i];}
template<class T> void fin(vector<vector<T>> &v){ int n=v.size(); int m=v[0].size(); for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin>>v[i][j];}

int lcm(int a,int b){ return ((a/__gcd(a,b))*b);}
ll power(ll x, ll y){ ll res = 1ll; while (y > 0ll) { if (y & 1ll)res = res * x; y = y >> 1ll; x = x * x;}return res;}
ll power_mod(ll x, ll y,ll mod){ ll res = 1ll; while (y > 0ll) { if (y & 1ll) res = (res*x)%mod; y = y >> 1ll; x = (x*x)%mod;}return res;}

vector<int> prime;
void getprime(int N){ 
    vector<int> lp(N+1);
    for (int i=2; i<=N;i++) {
    if (lp[i]==0) {
            lp[i]=i;
            prime.push_back(i);
        }
        for (int j=0; j <(int)prime.size() && prime[j] <= lp[i] && i*prime[j] <= N; ++j) {
            lp[i * prime[j]] = prime[j];
        }
    }
}

void task();

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
      int t=1;
      // cin>>t;
    while(t--)
      task();
    return 0;
}

int longestValidParentheses(string s) {
    stack<pair<char, int>> st;
    int n = s.size();
    string v(n, '0');
    
    for(int i=0; i<n; i++){
        if(s[i]=='(') st.push({'(', i});
        else if(!st.empty()){
            if(st.top().first=='(') v[i]=v[st.top().second]='1';
            st.pop();
        }
    }
    int temp=0, ans=0;
    for(char c: v){
        if(c=='1') temp++;
        else temp=0;
        ans = max(ans, temp);
    }
    return ans;
}

void task(){
    string s;
    cin>>s;
    int ans = longestValidParentheses(s);
    cout<<"ans: "<<ans<<endl;
}