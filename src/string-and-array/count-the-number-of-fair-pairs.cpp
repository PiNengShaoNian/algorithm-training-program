class Solution {
 public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    long long ans = 0;
    // lower - nums[i] <= nums[j] <= upper - nums[i]
    for (int j = 0; j < nums.size(); j++) {
      auto r = upper_bound(nums.begin(), nums.begin() + j, upper - nums[j]);
      auto l = lower_bound(nums.begin(), nums.begin() + j, lower - nums[j]);
      ans += r - l;
    }
    return ans;
  }
};