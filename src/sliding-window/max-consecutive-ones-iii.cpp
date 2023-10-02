class Solution {
 public:
  int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();

    int r = -1;
    int zero = 0;
    int ans = 0;
    for (int l = 0; l < n; l++) {
      while (r + 1 < n && (zero + !nums[r + 1]) <= k) {
        zero += !nums[r + 1];
        r++;
      }

      ans = max(ans, r - l + 1);
      zero -= !nums[l];
    }

    return ans;
  }
};