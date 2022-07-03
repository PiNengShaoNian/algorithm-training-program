class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        //dp[i]表示以nums[i]结尾能构成的最长递增子序列的长度为dp[i]
        vector<int> dp(n,1);
        //count[i]表示以nums[i]结尾最长递增子序列的个数为count[i]
        vector<int> count(n,1);

        //假设nums中最长递增子序列的长度为maxLen，那么结果就为count[x]的和其中x满足dp[x] = maxLen
        int maxLen = 1;
        int ans = 1;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i]) {
                    if(dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                    else if(dp[j] + 1 > dp[i]) {
                        count[i] = count[j];
                        dp[i] = dp[j] + 1;
                    }
                }
            }

            if(dp[i] > maxLen) {
                ans = count[i];
                maxLen = dp[i];
            }
            else if(dp[i] == maxLen) {
                ans += count[i];
            }
        }

        return ans;
    }

};