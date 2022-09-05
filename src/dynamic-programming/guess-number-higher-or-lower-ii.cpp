class Solution {
public:
    int getMoneyAmount(int n) {
        //dp[i][j]表示在区间[i,j]内猜数字需要的最少现金，其中最小状态dp[i][i]为零
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));

        //枚举区间长度
        for(int len = 2; len <= n; ++len) {
            //枚举区间起始位置
            for(int i = 1; i + len - 1 <= n; ++i) {
                //计算区间结束位置
                int j = i + len - 1;
                int min_cost = INT_MAX;
                //枚举在该区间猜那个数字需要的现金最小
                for(int k = i; k <= j; ++k) {
                    min_cost = min(min_cost, 
                                   //如果猜了数字k那么需要的最小现金就是dp[i][k - 1]和dp[k + 1][j]中的最大值
                                   k + max(dp[i][k - 1], dp[k + 1][j]));
                }

                dp[i][j] = min_cost;
            }
        }

        return dp[1][n];
    }
};