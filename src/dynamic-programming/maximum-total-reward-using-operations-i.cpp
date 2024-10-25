class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        int m = rewardValues.back();
        // dp[i]表示是否可以获得i个奖励
        // 如果数组中最大的奖励值为m那么我们能获得的最大奖励为2 * m - 1(如果我们选择m作为候选那么此时我们拥有的奖励一定不会超过m - 1)
        vector<int> dp(2 * m);
        dp[0] = 1;
        // 枚举奖励候选
        for (int reword : rewardValues) {
            // 如果选择挑选reword，那么我们挑选后的能获得奖励范围一定在[reword,2 * reword * 2 - 1]
            for (int j = 2 * reword - 1; j >= reword; j--) {
                // 判断如果挑选了reword能否从之前的状态转移过来
                if (dp[j - reword]) {
                    dp[j] = 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i]) {
                res = i;
            }
        }
        return res;
    }
};