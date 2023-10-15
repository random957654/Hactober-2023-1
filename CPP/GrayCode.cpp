#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define forn(i, n) for (int i = 0; i < int(n); i++)

// freopen('input.txt', 'r', stdin);
// freopen('output.txt', 'w', stdout);

vector<string> gray(int n)
{
    vector<string> v;
    if (n == 1)
    {
        v.PB("0");
        v.PB("1");
        return v;
    }
    vector<string> v1 = gray(n - 1);
    int size = v1.size();
    for (int i = 0; i < size; i++)
    {
        v.PB("0" + v1[i]);
    }
    for (int i = size - 1; i >= 0; i--)
    {
        v.PB("1" + v1[i]);
    }

    return v;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int _t;cin>>_t; while(_t--)
    int n;
    cin >> n;
    vector<string> ans = gray(n);

    for (auto x : ans)
    {
        cout << x << endl;
    }

    return 0;
}
