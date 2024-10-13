class Solution {
public:
    int twoEggDrop(int n) {
        // dp[i]表示要测试出一栋i层的楼的合适层数需要的最小操作次数
        vector<int> dp(n + 1, INT_MAX / 2);
        dp[0] = 0;
        // 枚举层数
        for (int i = 1; i <= n; i++) {
            // 枚举在哪个楼层投掷
            for (int k = 1; k <= i; k++) {
                // 在k层投出后分成两种情况
                // 1) 鸡蛋碎了，还剩一个鸡蛋只能通过从最底层一直投掷到k - 1层共需要k - 1次操作
                // 2) 鸡蛋没碎说明结果的范围是[k:i]，可以将其看成一个子问题
                dp[i] = min(dp[i], max(k - 1, dp[i - k]) + 1);
            }
        }

        return dp[n];
    }
};