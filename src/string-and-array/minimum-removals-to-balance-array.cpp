class Solution {
 public:
  int minRemoval(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = n;
    for (int l = 0, r = -1; l < n; l++) {
      while (r + 1 < n && (nums[r + 1] * 1.0) / k <= (nums[l] * 1.0)) {
        r++;
      }
      ans = min(ans, n - (r - l + 1));
    }
    return ans;
  }
};