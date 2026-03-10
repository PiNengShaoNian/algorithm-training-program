class Solution {
 public:
  int longestAlternatingSubarray(vector<int>& nums, int threshold) {
    int n = nums.size();
    int i = 0;
    int ans = 0;
    while (i < n) {
      if (nums[i] > threshold || nums[i] % 2) {
        i++;
        continue;
      }
      int start = i;
      i++;
      while (i < n && nums[i] <= threshold &&
             (nums[i] % 2 != nums[i - 1] % 2)) {
        i++;
      }
      ans = max(ans, i - start);
    }
    return ans;
  }
};