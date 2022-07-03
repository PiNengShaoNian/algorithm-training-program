class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        //dp[i]表示以i结尾的子串，能形成的最长的递增子串长度
        vector<int> dp(n,1);
        int ans = 1;

        for(int i = 1; i < n; ++i) {
            if(nums[i - 1] < nums[i]) {
                dp[i] = dp[i - 1] + 1;
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};