class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        //dp[i][j]表示从[i,j]走到右下角需要的最小初始HP
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        dp[n-1][m] = dp[n][m-1] = 1;

        for(int i = n - 1; i >= 0; --i) {
            for(int j = m - 1; j >= 0; --j) {
                int minin = min(dp[i + 1][j], dp[i][j + 1]);

                dp[i][j] = max(minin - dungeon[i][j], 1);
            }
        }

        return dp[0][0];
    }
};