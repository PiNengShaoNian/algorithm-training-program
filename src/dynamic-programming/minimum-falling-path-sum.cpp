class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = n - 2; i >= 0; --i) {
      for (int j = 0; j < m; ++j) {
        int min_num = matrix[i + 1][j];
        min_num = j - 1 >= 0 ? min(matrix[i + 1][j - 1], min_num) : min_num;

        min_num = j + 1 < m ? min(matrix[i + 1][j + 1], min_num) : min_num;

        matrix[i][j] += min_num;
      }
    }

    return *min_element(matrix[0].begin(), matrix[0].end());
  }
};

class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n));
    copy(matrix[0].begin(), matrix[0].end(), dp[0].begin());
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int mn = dp[i - 1][j];
        if (j - 1 >= 0) {
          mn = min(mn, dp[i - 1][j - 1]);
        }
        if (j + 1 < n) {
          mn = min(mn, dp[i - 1][j + 1]);
        }
        dp[i][j] = mn + matrix[i][j];
      }
    }
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
  }
};