class Solution {
 public:
  int largestMagicSquare(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    // 每一行的前缀和
    vector<vector<int>> rowsum(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      rowsum[i][0] = grid[i][0];
      for (int j = 1; j < n; ++j) {
        rowsum[i][j] = rowsum[i][j - 1] + grid[i][j];
      }
    }
    // 每一列的前缀和
    vector<vector<int>> colsum(m, vector<int>(n));
    for (int j = 0; j < n; ++j) {
      colsum[0][j] = grid[0][j];
      for (int i = 1; i < m; ++i) {
        colsum[i][j] = colsum[i - 1][j] + grid[i][j];
      }
    }

    // 从大到小枚举边长 edge
    for (int edge = min(m, n); edge >= 2; --edge) {
      // 枚举正方形的左上角位置 (i,j)
      for (int i = 0; i + edge <= m; ++i) {
        for (int j = 0; j + edge <= n; ++j) {
          // 计算每一行、列、对角线的值应该是多少（以第一行为样本）
          int stdsum = rowsum[i][j + edge - 1] - (j ? rowsum[i][j - 1] : 0);
          bool check = true;
          // 枚举每一行并用前缀和直接求和
          // 由于我们已经拿第一行作为样本了，这里可以跳过第一行
          for (int ii = i + 1; ii < i + edge; ++ii) {
            if (rowsum[ii][j + edge - 1] - (j ? rowsum[ii][j - 1] : 0) !=
                stdsum) {
              check = false;
              break;
            }
          }
          if (!check) {
            continue;
          }
          // 枚举每一列并用前缀和直接求和
          for (int jj = j; jj < j + edge; ++jj) {
            if (colsum[i + edge - 1][jj] - (i ? colsum[i - 1][jj] : 0) !=
                stdsum) {
              check = false;
              break;
            }
          }
          if (!check) {
            continue;
          }
          // d1 和 d2 分别表示两条对角线的和
          // 这里 d 表示 diagonal
          int d1 = 0, d2 = 0;
          // 不使用前缀和，直接遍历求和
          for (int k = 0; k < edge; ++k) {
            d1 += grid[i + k][j + k];
            d2 += grid[i + k][j + edge - 1 - k];
          }
          if (d1 == stdsum && d2 == stdsum) {
            return edge;
          }
        }
      }
    }

    return 1;
  }
};
