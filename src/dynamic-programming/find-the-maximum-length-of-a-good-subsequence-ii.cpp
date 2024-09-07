class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        int len = nums.size();
        // dp[i][j]表示已数字nums[i]结尾并且其中有k组前后不相同的的子序列，它的最大长度
        vector<vector<int>> dp(len, vector<int>(k + 1, -1));
        // 枚举子序列的末尾元素nums[i]
        for (int i = 0; i < len; i++) {
            dp[i][0] = 1;
            // 枚举子序列中前后不同的序列的个数
            for (int j = 0; j <= k; j++) {
                // 枚举改子序列的倒数第二个元素nums[x]
                for (int x = 0; x < i; x++) {
                    // dp[i][j] = max(dp[x][j - (nums[x] != nums[i])] + 1)，其中x < i,j <= k
                    int add = (nums[i] != nums[x]);
                    if (j - add >= 0 && dp[x][j - add] != -1) {
                        dp[i][j] = max(dp[i][j], dp[x][j - add] + 1);
                    }
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};