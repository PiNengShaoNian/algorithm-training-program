class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            vector<int> dp(n, 1);
    
            int maxVal = nums[0];
            int maxSize = 1;
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (nums[i] % nums[j] == 0) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
    
                if (dp[i] > maxSize) {
                    maxSize = dp[i];
                    maxVal = nums[i];
                }
            }
    
            vector<int> ans;
            if (maxSize == 1) {
                ans.push_back(nums[0]);
                return ans;
            }
    
            for (int i = n - 1; i >= 0 && maxSize > 0; i--) {
                if (dp[i] == maxSize && maxVal % nums[i] == 0) {
                    ans.push_back(nums[i]);
                    maxVal = nums[i];
                    maxSize--;
                }
            }
            return ans;
        }
    };