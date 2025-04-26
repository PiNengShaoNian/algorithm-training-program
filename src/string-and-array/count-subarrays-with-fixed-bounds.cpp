class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    int border = -1;
    int last_min = -1;
    int last_max = -1;
    long long ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < minK || nums[i] > maxK) {
        border = i;
        last_max = last_min = -1;
      }

      if (nums[i] == minK) {
        last_min = i;
      }
      if (nums[i] == maxK) {
        last_max = i;
      }
      if (last_min != -1 && last_max != -1) {
        ans += min(last_min, last_max) - border;
      }
    }
    return ans;
  }
};