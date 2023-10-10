class Solution {
 public:
  static constexpr int mod = 1e9 + 7;
  int sumDistance(vector<int>& nums, string s, int d) {
    int n = nums.size();
    vector<int64_t> pos(n);
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L') {
        pos[i] = (int64_t)nums[i] - d;
      } else {
        pos[i] = (int64_t)nums[i] + d;
      }
    }

    sort(pos.begin(), pos.end());
    int64_t res = 0;
    int64_t sum = 0;
    for (int i = 0; i < n; i++) {
      res = (res + pos[i] * i - sum) % mod;
      sum += pos[i];
    }

    return res;
  }
};