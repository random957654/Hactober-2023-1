#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int romanToDecimal(string &str) {
        unordered_map<char, int> m = {{'I', 1}, {'V', 5}, 
                                      {'X', 10}, {'L', 50}, 
                                      {'C', 100},{'D', 500}, 
                                      {'M', 1000}};
        int num=m[str.back()];
        for(int i=0; i<str.length()-1; i++)
        {
            num += m[str[i]] < m[str[i+1]] ? -m[str[i]] : m[str[i]];
        }
        return num;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
