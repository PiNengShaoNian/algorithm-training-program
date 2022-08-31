class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        //dp[i][j]表示在前i枚硬币中有j枚朝上的概率，其中i从0开始
        //所以dp[n][target]就是最终答案
        vector<vector<double>> dp(n + 1, vector<double>(target + 1, 0));
        //初始化前0枚硬币，有0枚朝上的概率为1
        dp[0][0] = 1.0;
        for(int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i - 1][0] * (1 - prob[i - 1]);
        }

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= i && j <= target; ++j) {
                dp[i][j] = //前i-1枚就已经有j枚朝上了那第i枚就没朝上
                           dp[i - 1][j] * (1 - prob[i - 1]) + 
                           //前i-1枚中只有j-1枚朝上，那么第i枚就需要朝上
                           dp[i - 1][j - 1] * prob[i - 1];
            }
        }

        return dp[n][target];
    }
};