class Solution {
public:
    //动态规划解法，时间复杂度O(n)由于数据量大会超时
    bool canWinNim(int n) {
        //dp[i]表示当有i块石头时，先手的人是否能获胜
        vector<bool> dp(n + 1, false);
        dp[1] = dp[2] = dp[3] = true;

        for(int i = 4; i <= n; ++i) {
            dp[i] = !(dp[i - 1] && dp[i - 2] && dp[i - 3]);
        }

        return dp[n];
    }

    //通过观察当n为4的倍数时，先手的人会失败，所以直接返回n % 4 != 0即可
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};