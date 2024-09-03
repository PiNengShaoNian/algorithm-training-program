class Solution {
 public:
  long long maxStrength(vector<int>& nums) {
    long long max_prod = nums[0];
    long long min_prod = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      long long temp = max_prod;
      max_prod = max(max(nums[i] * 1ll, temp),
                     max(min_prod * nums[i], temp * nums[i]));
      min_prod = min(min(nums[i] * 1ll, min_prod),
                     min(min_prod * nums[i], temp * nums[i]));
    }
    return max_prod;
  }
};