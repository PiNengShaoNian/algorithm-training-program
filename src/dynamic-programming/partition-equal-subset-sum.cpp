class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int sum = 0;
            int maxVal = nums[0];
            int n = nums.size();
            for (int num : nums) {
                sum += num;
                maxVal = max(maxVal, num);
            }
    
            if ((sum % 2 != 0) || (maxVal > sum / 2)) {
                return false;
            }
    
            int target = sum / 2;
            vector<int> dp(target + 1, 0);
            dp[0] = true;
            for (int i = 0; i < n; i++) {
                int k = nums[i];
                for (int j = target; j >= k; j--) {
                    dp[j] = dp[j] || dp[j - k];
                }
            }
            return dp[target];
        }
    };