class Solution {
public:
    using ll = long long;
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        // dp[i][0]表示在[0, i]范围内最后依次取A类型能量的情况下能获得的最大能量
        // dp[i][1]表示在[0, i]范围内最后依次取B类型能量的情况下能获得的最大能量
        vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + energyDrinkA[i - 1];
            dp[i][1] = dp[i - 1][1] + energyDrinkB[i - 1];
            if (i >= 2) {
                dp[i][0] = max(dp[i][0], dp[i - 2][1] + energyDrinkA[i - 1]);
                dp[i][1] = max(dp[i][1], dp[i - 2][0] + energyDrinkB[i - 1]);
            }
        }
        return max(dp[n][0], dp[n][1]);
    }
};