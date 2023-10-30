class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    // f[i][d]表示以nums[i]为结尾，等差为d,长度至少大于等于2的等差序列数量
    vector<unordered_map<long long, int>> f(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        long long d = 1LL * nums[i] - nums[j];
        auto it = f[j].find(d);
        int cnt = it == f[j].end() ? 0 : it->second;
        ans += cnt;
        f[i][d] += cnt + 1;
      }
    }
    return ans;
  }
};