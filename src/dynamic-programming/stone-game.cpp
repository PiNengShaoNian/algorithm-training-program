//这题只是predict-the-winner的一个特例，直接照搬predict-the-winner代码过来就行
class Solution {
public:
    bool stoneGame(vector<int>& nums) {
        int n = nums.size();
        //dp[i][j]表示在nums[i:j]区间内先手的那个玩家能比后手的玩家多多少分
        vector<vector<int>> dp(n, vector<int>(n));

        for(int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }

        for(int len = 2; len <= n; ++len) {
            for(int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                
                //如果一个人在nums[i:j]区间内选择先手，它可以选择nums[i]或者nums[j]
                //那么我们需要减去一个人在nums[i+1:j]或者nums[i:j-1]区间内先手
                //的领先分数，就是dp[i][j]
                dp[i][j] = max(
                    nums[i] - dp[i + 1][j],
                    nums[j] - dp[i][j - 1]
                );
            }
        }

        return dp[0][n - 1] >= 0;
    }
};