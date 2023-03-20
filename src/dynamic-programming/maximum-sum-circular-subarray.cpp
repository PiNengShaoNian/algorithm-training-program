class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpMax(n);
        vector<int> dpMin(n);
        int maxSum, minSum, sum; 
        sum = maxSum = minSum = dpMax[0] = dpMin[0] = nums[0];


        for(int i = 1; i < n; ++i) {
            dpMax[i] = max(dpMax[i - 1] + nums[i], nums[i]);
            dpMin[i] = min(dpMin[i - 1] + nums[i], nums[i]);
            sum += nums[i];
            maxSum = max(maxSum, dpMax[i]);
            minSum = min(minSum, dpMin[i]);
        }

        return max(maxSum, sum - minSum == 0 ? maxSum : sum - minSum);
    }
};