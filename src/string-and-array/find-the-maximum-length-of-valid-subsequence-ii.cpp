class Solution {
 public:
  int maximumLength(vector<int>& nums, int k) {
    int ans = 0;
    vector f(k, vector<int>(k));
    for (int x : nums) {
      x %= k;
      for (int y = 0; y < k; y++) {
        f[y][x] = f[x][y] + 1;
        ans = max(ans, f[y][x]);
      }
    }
    return ans;
  }
};