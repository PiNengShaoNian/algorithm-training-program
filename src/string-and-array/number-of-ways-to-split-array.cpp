class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> preSum(n + 1);
        for (int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (preSum[i + 1] >= preSum[n] - preSum[i + 1]) {
                ans++;
            }
        }
        return ans;
    }
};