class Solution {
 public:
  long long maxSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    long long preSum = 0;
    long long maxSum = LONG_LONG_MIN;
    vector<long long> kSum(k, LONG_LONG_MAX / 2);
    kSum[k - 1] = 0;
    for (int i = 0; i < nums.size(); i++) {
      preSum += nums[i];
      maxSum = max(preSum - kSum[i % k], maxSum);
      kSum[i % k] = min(preSum, kSum[i % k]);
    }
    return maxSum;
  }
};