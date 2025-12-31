class Solution {
 public:
  int numMagicSquaresInside(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;
    for (int r = 0; r < rows - 2; r++) {
      for (int c = 0; c < cols - 2; c++) {
        if (grid[r + 1][c + 1] != 5) {
          continue;
        }
        if (isMagicSquare(grid[r][c], grid[r][c + 1], grid[r][c + 2],
                          grid[r + 1][c], grid[r + 1][c + 1],
                          grid[r + 1][c + 2], grid[r + 2][c],
                          grid[r + 2][c + 1], grid[r + 2][c + 2])) {
          count++;
        }
      }
    }

    return count;
  }

 private:
  bool isMagicSquare(int a, int b, int c, int d, int e, int f, int g, int h,
                     int i) {
    vector<int> vals = {a, b, c, d, e, f, g, h, i};
    vector<int> frequency(16, 0);
    for (int value : vals) {
      if (value < 1 || value > 9) {
        return false;
      }
      frequency[value]++;
    }

    for (int num = 1; num <= 9; num++) {
      if (frequency[num] != 1) {
        return false;
      }
    }

    return (a + b + c == 15 &&  // 第一行
            d + e + f == 15 &&  // 第二行
            g + h + i == 15 &&  // 第三行
            a + d + g == 15 &&  // 第一列
            b + e + h == 15 &&  // 第二列
            c + f + i == 15 &&  // 第三列
            a + e + i == 15 &&  // 主对角线
            c + e + g == 15);   // 副对角线
  }
};