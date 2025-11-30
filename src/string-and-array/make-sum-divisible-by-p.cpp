class Solution {
 public:
  int minSubarray(vector<int>& nums, int p) {
    int n = nums.size(), s[n + 1];
    s[0] = 0;
    for (int i = 0; i < n; i++) {
      s[i + 1] = (s[i] + nums[i]) % p;
    }
    int x = s[n];
    if (x == 0) {
      return 0;
    }

    int ans = n;
    unordered_map<int, int> last;
    for (int i = 0; i <= n; ++i) {
      last[s[i]] = i;
      auto it = last.find((s[i] - x + p) % p);
      if (it != last.end()) {
        ans = min(ans, i - it->second);
      }
    }
    return ans < n ? ans : -1;
  }
};