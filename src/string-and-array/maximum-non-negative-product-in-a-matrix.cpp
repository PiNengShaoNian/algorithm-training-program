class Solution {
 public:
  int maxProductPath(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    long long MOD = 1e9 + 7;

    // 使用 long long 防止溢出
    vector<vector<long long>> dpMax(n, vector<long long>(m));
    vector<vector<long long>> dpMin(n, vector<long long>(m));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 && j == 0) {
          dpMax[i][j] = dpMin[i][j] = grid[0][0];
        } else if (i == 0) {
          dpMax[i][j] = dpMin[i][j] = grid[i][j] * dpMin[i][j - 1];
        } else if (j == 0) {
          dpMax[i][j] = dpMin[i][j] = grid[i][j] * dpMin[i - 1][j];
        } else {
          long long a = dpMax[i - 1][j] * grid[i][j];
          long long b = dpMin[i - 1][j] * grid[i][j];
          long long c = dpMax[i][j - 1] * grid[i][j];
          long long d = dpMin[i][j - 1] * grid[i][j];
          dpMax[i][j] = max({a, b, c, d});
          dpMin[i][j] = min({a, b, c, d});  // 修复笔误
        }
      }
    }

    long long res = dpMax[n - 1][m - 1];
    return res < 0 ? -1 : res % MOD;  // 加上取余
  }
};