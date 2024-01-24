class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    // 由于从起点到终点，和终点到起点的路径是等价的所以可以将这题等价转换为
    // 两个人同时从(0, 0)出发，走到(n - 1, n - 1)两个人能收集到的最大数量

    // f[k][x1][x2]表示走了k步，第一个人的纵坐标是x1, 第二个人的纵坐标是x2
    // 从(0, 0)走到(x1, k - x1), (x2, k - x2)
    vector<vector<vector<int>>> f(
        n * 2 - 1, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
    f[0][0][0] = grid[0][0];

    for (int k = 1; k < n * 2 - 1; k++) {
      for (int x1 = max(k - n + 1, 0); x1 <= min(k, n - 1); x1++) {
        int y1 = k - x1;
        if (grid[x1][y1] == -1) {
          continue;
        }
        for (int x2 = x1; x2 <= min(k, n - 1); x2++) {
          int y2 = k - x2;
          if (grid[x2][y2] == -1) {
            continue;
          }
          int res = f[k - 1][x1][x2];  // 都往右
          if (x1) {
            res = max(res, f[k - 1][x1 - 1][x2]);  // 往下, 往右
          }
          if (x2) {
            res = max(res, f[k - 1][x1][x2 - 1]);  // 往右, 往下
          }
          if (x1 && x2) {
            res = max(res, f[k - 1][x1 - 1][x2 - 1]);  // 都往下
          }
          res += grid[x1][y1];
          if (x1 != x2) {  // 避免重复摘同一个樱桃
            res += grid[x2][y2];
          }
          f[k][x1][x2] = res;
        }
      }
    }
    return max(f.back().back().back(), 0);
  }
};