class Solution {
 public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int all = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    if (all % k != 0) {
      return false;
    }
    int per = all / k;
    sort(nums.begin(), nums.end());
    if (nums.back() > per) {
      return false;
    }
    vector<int> dp(1 << n, true);
    function<bool(int, int)> dfs = [&](int s, int p) -> bool {
      if (s == 0) {
        return true;
      }
      if (!dp[s]) {
        return false;
      }
      dp[s] = false;
      for (int i = 0; i < n; i++) {
        if (nums[i] + p > per) {
          break;
        }
        if ((s >> i) & 1) {
          if (dfs(s ^ (1 << i), (p + nums[i]) % per)) {
            return true;
          }
        }
      }
      return false;
    };
    return dfs((1 << n) - 1, 0);
  }
};