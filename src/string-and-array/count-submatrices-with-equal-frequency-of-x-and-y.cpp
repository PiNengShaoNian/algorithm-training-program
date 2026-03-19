class Solution {
 public:
  int numberOfSubmatrices(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    // 用于记录每一列到当前行为止，X 和 Y 的累计数量
    vector<int> colX(m, 0);
    vector<int> colY(m, 0);
    int ans = 0;

    for (int i = 0; i < n; i++) {
      int current_row_total_X = 0;
      int current_row_total_Y = 0;

      for (int j = 0; j < m; j++) {
        // 1. 更新当前列的计数
        if (grid[i][j] == 'X')
          colX[j]++;
        else if (grid[i][j] == 'Y')
          colY[j]++;

        // 2. 累加 [0,0] 到 [i,j] 的总量
        // 当前矩形内的总数 = 每一列到当前行计数之和
        current_row_total_X += colX[j];
        current_row_total_Y += colY[j];

        // 3. 判断条件
        if (current_row_total_X > 0 &&
            current_row_total_X == current_row_total_Y) {
          ans++;
        }
      }
    }
    return ans;
  }
};