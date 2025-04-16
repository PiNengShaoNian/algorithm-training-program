class Solution {
 public:
  long long countGood(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    int n = nums.size();
    int r = -1;
    int same = 0;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
      while (same < k && r + 1 < n) {
        r++;
        same += cnt[nums[r]];
        cnt[nums[r]]++;
      }

      if (same >= k) {
        ans += n - r;
      }
      cnt[nums[i]]--;
      same -= cnt[nums[i]];
    }
    return ans;
  }
};