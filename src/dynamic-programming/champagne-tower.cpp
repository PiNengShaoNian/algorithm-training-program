double dp[101][101];

class Solution {
public:
    //动态规划递推模拟，时间复杂度O(N^2)
    double champagneTower(int poured, int query_row, int query_glass) {
        memset(dp,0,sizeof(dp));
        dp[0][0] = poured;

        for(int i = 0; i <= query_row; ++i) {
            for(int j = 0; j < i + 1; ++j) {
                double prev = dp[i][j];
                double rest = prev - 1.0;

                if(rest > 0.0) {
                    double half = rest / 2;
                    dp[i+1][j] += half;
                    dp[i+1][j+1] += half;
                }
            }
        }

        return dp[query_row][query_glass] >= 1.0 ? 1.0 : dp[query_row][query_glass];
    }
};