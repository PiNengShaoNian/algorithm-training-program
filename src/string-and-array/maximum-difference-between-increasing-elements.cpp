class Solution {
 public:
  int maximumDifference(vector<int>& nums) {
    int n = nums.size();
    int premin = nums[0];
    int ans = -1;
    for (int j = 0; j < nums.size(); j++) {
      if (nums[j] > premin) {
        ans = max(nums[j] - premin, ans);
      } else {
        premin = nums[j];
      }
    }
    return ans;
  }
};