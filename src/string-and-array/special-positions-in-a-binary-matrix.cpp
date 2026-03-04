class Solution {
 public:
  int numSpecial(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> rows_cnt(n, 0);
    vector<int> cols_cnt(m, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mat[i][j] == 1) {
          rows_cnt[i]++;
          cols_cnt[j]++;
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mat[i][j] == 1 && rows_cnt[i] == 1 && cols_cnt[j] == 1) {
          ans++;
        }
      }
    }
    return ans;
  }
};