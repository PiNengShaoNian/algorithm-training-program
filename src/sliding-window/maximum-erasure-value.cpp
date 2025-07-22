class Solution {
 public:
  int maximumUniqueSubarray(vector<int>& nums) {
    int r = -1;
    int n = nums.size();
    unordered_set<int> seen;
    int ans = 0;
    int score = 0;
    for (int l = 0; l < n; l++) {
      while (r + 1 < n && !seen.count(nums[r + 1])) {
        score += nums[r + 1];
        seen.insert(nums[r + 1]);
        r++;
      }

      ans = max(ans, score);
      seen.erase(nums[l]);
      score -= nums[l];
    }
    return ans;
  }
};