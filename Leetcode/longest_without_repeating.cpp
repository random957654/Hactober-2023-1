class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int tot = 0;  
        for (int i = 0; i < size; i++) {
            vector<bool> checked(256);  
    
            for (int j = i; j < size; j++) {
                if (checked[s[j]] == true)
                    break;
                else {
                    tot = max(tot, j - i + 1);
                    checked[s[j]] = true;
                }
            }
            checked[s[i]] = false;
        }
        return tot;
    }
};
