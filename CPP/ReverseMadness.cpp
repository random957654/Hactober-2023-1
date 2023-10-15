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
#define debug(a)         cout<<a<<endl;

int main()
{
    fast_io;
    int test;
    cin >> test;
    while (test--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int a[k];
        int b[k];
        loop(i,k) {
            cin >> a[i];
            a[i]--;
        }
        loop(i,k) {
            cin >> b[i];
            b[i]--;
        }
        int q;
        cin >> q;
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            cnt[x - 1]++;
        }
        string ans = "";
        loop(i,k){
            string s1 = s.substr(a[i], b[i] - a[i] + 1);
            int sum = 0;
            int l = a[i];
            int r = b[i];
            for (int j = l; j <= (l + r) / 2; j++) {
                sum += cnt[j] + cnt[r - j + l];
                if (sum & 1)
                    swap(s1[j - l], s1[r - j]);
            }
            ans += s1;
        }
        cout << ans << '\n';

    }

    return 0;
}
