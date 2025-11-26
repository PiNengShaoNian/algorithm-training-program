class Solution {
 public:
  int numberOfPaths(vector<vector<int>>& grid, int k) {
    constexpr static int MOD = 1'000'000'007;
    int m = grid.size();
    int n = grid[0].size();
    vector memo(m, vector(n, vector<int>(k, -1)));

    // dfs(i, j, s): number of paths to (i, j) with sum % k == s
    auto dfs = [&](this auto&& dfs, int i, int j, int s) -> int {
      if (i < 0 || j < 0) {
        return 0;
      }
      int pre_s = ((s - grid[i][j]) % k + k) % k;
      if (i == 0 && j == 0) {
        return pre_s == 0;
      }
      int& res = memo[i][j][s];
      if (res != -1) {
        return res;
      }
      return res = (dfs(i - 1, j, pre_s) + dfs(i, j - 1, pre_s)) % MOD;
    };

    return dfs(m - 1, n - 1, 0);
  }
};