class Solution {
    public:
        static constexpr int INF = 0x3f3f3f3f;
        int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
            int n = floor.size();
            // dp[i][j]表示覆盖了[1:i]范围内的砖块，使用了j个地毯的情况下露出白色砖块的最小数量
            vector<vector<int>> dp(n + 1, vector<int>(numCarpets + 1, INF));
    
            for (int i = 0; i <= numCarpets; i++) {
                dp[0][i] = 0;
            }
    
            for (int i = 1; i <= n; i++) {
                dp[i][0] = dp[i - 1][0] + (floor[i - 1] == '1');
            }
    
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= numCarpets; j++) {
                    dp[i][j] = min(dp[i - 1][j] + (floor[i - 1] == '1'), dp[max(i - carpetLen, 0)][j - 1]);
                }
            }
            return dp[n][numCarpets];
        }
    };