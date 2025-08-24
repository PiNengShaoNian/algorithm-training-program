class Solution {
 public:
  int longestSubarray(vector<int>& nums) {
    int ans = 0;
    int count = 0;
    int r = -1;
    int n = nums.size();
    for (int l = 0; l < n; l++) {
      while (r + 1 < n && (nums[r + 1] == 1 || count == 0)) {
        count += nums[r + 1] == 0;
        r++;
      }
      ans = max(ans, r - l);
      count -= nums[l] == 0;
    }
    return ans;
  }
};