class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        //dp[i][j]表示以[i,j]为右下角的正方形数量
        vector<vector<int>> dp(n,vector<int>(m, 0));
        
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(i == 0 && j == 0) {
                    dp[i][j] = matrix[0][0];
                }
                else if(i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j];
                }
                else if(matrix[i][j] == 1){
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
            
                ans += dp[i][j];
            }
        }

        return ans;
    }
};