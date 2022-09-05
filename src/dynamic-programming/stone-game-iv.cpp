class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
    
        //dp[i]表示在总共有i个石子情况下，先手的人是否能赢
        dp[1] = true;

        for(int i = 2; i <= n; ++i) {
            for(int j = 1; j * j <= i; ++j) {
                //已经能赢了，不需要在判断了
                if(dp[i]) break;
                //只要存在一个让下一轮玩家输的情况,那在i上先手的玩家就能赢
                dp[i] = !dp[i - j * j];
            }
        }

        return dp[n];
    }
};