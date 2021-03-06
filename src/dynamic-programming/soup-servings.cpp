class Solution {
public:
    double soupServings(int n) {
        //数字都是25的倍数，将所有数字都缩小25倍
        n = n / 25 +  (n % 25 ? 1 : 0);
        if(n >= 200) return 1;
        //dp[i][j]表示A汤剩下i，B汤剩下j此时的概率
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));

        dp[0][0] = 0.5;
        for(int i = 1; i <= n; ++i) dp[0][i] = 1.0;

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                // (4, 0)，(3, 1)，(2, 2) 和 (1, 3)。
                double val = 0;

                val += dp[max(i - 4, 0)][j] + dp[max(i - 3, 0)][j - 1] + dp[max(i - 2, 0)][max(j - 2, 0)] +
                       dp[i - 1][max(j - 3, 0)];

                dp[i][j] = val / 4;
            }
        }

        return dp[n][n];
    }
};