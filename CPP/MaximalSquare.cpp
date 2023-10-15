//problem link: https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        int max_side = 0;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    int topLeft = dp[i][j];
                    int top = dp[i][j+1];
                    int left = dp[i+1][j];
                    dp[i+1][j+1] = min({topLeft, top, left}) + 1;
                    max_side = max(max_side, dp[i+1][j+1]);
                }
            }
        }
        
        return max_side * max_side;
    }
};
