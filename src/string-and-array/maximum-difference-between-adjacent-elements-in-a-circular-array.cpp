class Solution {
 public:
  int maxAdjacentDistance(vector<int>& nums) {
    int ans = abs(nums[1] - nums[0]);
    int n = nums.size();
    for (int i = 1; i < n; i++) {
      ans = max(ans, abs(nums[i] - nums[i - 1]));
    }
    return max(ans, abs(nums.back() - nums[0]));
  }
};