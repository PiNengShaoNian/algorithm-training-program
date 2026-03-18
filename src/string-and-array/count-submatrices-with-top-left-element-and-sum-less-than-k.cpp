class Solution {
 public:
  int countSubmatrices(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> cols(m);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = 0; j < m; j++) {
        cols[j] += grid[i][j];
        sum += cols[j];
        if (sum <= k) {
          ans++;
        }
      }
    }
    return ans;
  }
};