class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        //dp[i][j]表示以[i,j]为右下角的最大正方形边长
        vector<vector<int>> dp(n,vector<int>(m, 0));

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(matrix[i][j] == '1') {
                    dp[i][j] = 1;
                    ans = 1;
                }
                
            }
        }
        
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
               if(matrix[i][j] == '1') {
                   dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
               }

               ans = max(ans, dp[i][j]);
            }
        }

        return ans * ans;
    }
};