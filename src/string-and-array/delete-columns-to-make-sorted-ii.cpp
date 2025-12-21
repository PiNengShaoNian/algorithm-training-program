class Solution {
 public:
  int minDeletionSize(vector<string>& strs) {
    int n = strs.size();
    int m = strs[0].size();
    int ans = 0;
    vector<string> a(n);
    for (int j = 0; j < m; j++) {
      bool del = false;
      for (int i = 0; i < n - 1; i++) {
        if (a[i] + strs[i][j] > a[i + 1] + strs[i + 1][j]) {
          del = true;
          ans++;
          break;
        }
      }

      if (!del) {
        for (int i = 0; i < n; i++) {
          a[i] += strs[i][j];
        }
      }
    }
    return ans;
  }
};