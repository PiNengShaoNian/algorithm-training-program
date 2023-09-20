class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n));
    int l = 0;
    int r = n - 1;
    int t = 0;
    int b = n - 1;
    int num = 1;
    int target = n * n;
    while (num <= target) {
      for (int i = l; i <= r; i++) ans[t][i] = num++;
      t++;

      for (int i = t; i <= b; i++) ans[i][r] = num++;
      r--;

      for (int i = r; i >= l; i--) ans[b][i] = num++;
      b--;

      for (int i = b; i >= t; i--) ans[i][l] = num++;
      l++;
    }

    return ans;
  }
};