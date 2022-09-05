class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        //dp[i][j]表示piles[i,n - 1]范围内且此时的M为j的先手人能获得的最大石子
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        
        int sum = 0;
        //i从后往前枚举，到时候i + X就是子状态
        for(int i = n - 1; i >= 0; --i) {
            sum += piles[i];

            for(int M = 1; M <= n; ++M) {
                if(i + 2 * M >= n) {
                    dp[i][M] = sum;
                }
                else {
                    for(int X = 1; X <= 2 * M; ++X) {
                        dp[i][M] = max(sum - dp[i + X][max(X, M)], dp[i][M]);
                    }
                }
            }
        }

        return dp[0][1];
    }
};