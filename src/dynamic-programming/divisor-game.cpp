class Solution {
public:
    bool divisorGame(int n) {
        //dp[i]表示当n为i时，先手的人是否能获胜
        vector<bool> dp(n + 1, false);

        //没有数字x在0到1之间，故dp[1]为false
        dp[1] = false;

        for(int i = 2; i <= n; ++i) {
            for(int x = 1; x < i; ++x) {
                if(dp[i]) break;
                if(i % x == 0) {
                    //只要存在一种情况，让后手的失败，那在n为i时先手的人就能成功
                    dp[i] = !dp[i - x];
                }
            }
        }

        return dp[n];
    }
};