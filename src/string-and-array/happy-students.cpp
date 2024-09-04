class Solution {
 public:
  int countWays(vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    sort(nums.begin(), nums.end());
    for (int k = 0; k <= n; k++) {
      // 前k个选中的元素是否都小于k
      if (k > 0 && nums[k - 1] >= k) {
        continue;
      }
      // 后n - k个元素是否都大于k
      if (k < n && nums[k] <= k) {
        continue;
      }
      res++;
    }
    return res;
  }
};