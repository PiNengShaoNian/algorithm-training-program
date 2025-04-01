class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            int n = questions.size();
            // dp[i]表示只解决[i, n - 1]范围内的问题能得到的最大的分数
            vector<long long> dp(n + 1);
            for (int i = n - 1; i >= 0; i--) {
                dp[i] = max(dp[i + 1], questions[i][0] + dp[min(n, i + questions[i][1] + 1)]);
            }
            return dp[0];
        }
    };