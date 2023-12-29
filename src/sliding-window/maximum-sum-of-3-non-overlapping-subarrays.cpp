class Solution {
 public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    vector<int> ans;
    int sum1 = 0, sum2 = 0, sum3 = 0;
    int maxSum1 = 0, maxSum12 = 0, maxTotal = 0;
    int maxSum1Idx = 0, maxSum12Idx1 = 0, maxSum12Idx2 = 0;
    int n = nums.size();

    for (int i = 2 * k; i < n; i++) {
      sum1 += nums[i - k * 2];
      sum2 += nums[i - k];
      sum3 += nums[i];

      if (i >= k * 3 - 1) {
        if (sum1 > maxSum1) {
          maxSum1Idx = i - k * 3 + 1;
          maxSum1 = sum1;
        }

        if (maxSum1 + sum2 > maxSum12) {
          maxSum12Idx1 = maxSum1Idx;
          maxSum12Idx2 = i - k * 2 + 1;
          maxSum12 = maxSum1 + sum2;
        }

        if (maxSum12 + sum3 > maxTotal) {
          maxTotal = maxSum12 + sum3;
          ans = {maxSum12Idx1, maxSum12Idx2, i - k + 1};
        }

        sum1 -= nums[i - k * 3 + 1];
        sum2 -= nums[i - k * 2 + 1];
        sum3 -= nums[i - k + 1];
      }
    }

    return ans;
  }
};