//problem link: https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    vector<int> NSL(vector<int>& heights){
        int n = heights.size();
        vector<int> ans;
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty())ans.push_back(-1);
            else ans.push_back(st.top());
            st.push(i);
        }
        return ans;
    }
    vector<int> NSR(vector<int>& heights){
        int n = heights.size();
        vector<int> ans;
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty())ans.push_back(n);
            else ans.push_back(st.top());
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left = NSL(heights);
        vector<int> right = NSR(heights);
        vector<int> width(n);
        for(int i=0; i<n; i++){
            width[i] = heights[i]*(right[i]-left[i]-1);
        }
        int ans = *max_element(width.begin(),width.end());
        return ans;
    }
};
