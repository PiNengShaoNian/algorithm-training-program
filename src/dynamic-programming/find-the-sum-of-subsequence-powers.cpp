class Solution {
 public:
  using ump = unordered_map<int, int>;
  static constexpr int mod = 1e9 + 7;
  static constexpr int inf = 0x3f3f3f3f;
  int sumOfPowers(vector<int> &nums, int k) {
    int n = nums.size();
    int res = 0;
    // d[i][j][k]表示已nums[i]为结尾，长度为j能量为k的子序列有多少个
    vector<vector<ump>> d(n, vector<ump>(k + 1));
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
      // 设置一个初始值方便下面状态转移
      d[i][1][inf] = 1;
      for (int j = 0; j < i; j++) {
        int diff = abs(nums[i] - nums[j]);
        for (int p = 2; p <= k; p++) {
          for (auto &[v, cnt] : d[j][p - 1]) {
            d[i][p][min(diff, v)] = (d[i][p][min(diff, v)] + cnt) % mod;
          }
        }
      }
      for (auto &[v, cnt] : d[i][k]) {
        res = (res + 1ll * v * cnt % mod) % mod;
      }
    }
    return res;
  }
};