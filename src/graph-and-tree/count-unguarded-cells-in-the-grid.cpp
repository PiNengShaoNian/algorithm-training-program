class Solution {
 public:
  int countUnguarded(int m, int n, vector<vector<int>>& guards,
                     vector<vector<int>>& walls) {
    vector<vector<int>> grid(m, vector<int>(n));  // 网格状态数组
    queue<tuple<int, int, int>> q;                // 广度优先搜索队列
    // 每个方向的单位向量
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for (const auto& guard : guards) {
      grid[guard[0]][guard[1]] = -1;
      for (int k = 0; k < 4; ++k) {
        // 将四个方向视线对应的状态均添加进搜索队列中
        q.emplace(guard[0], guard[1], k);
      }
    }
    for (const auto& wall : walls) {
      grid[wall[0]][wall[1]] = -2;
    }
    while (!q.empty()) {
      auto [x, y, k] = q.front();
      q.pop();
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] >= 0) {
        // 沿着视线方向的下一个坐标合法，且不为警卫或墙
        if ((grid[nx][ny] & (1 << k)) == 0) {
          // 对应状态未遍历过
          grid[nx][ny] |= (1 << k);
          q.emplace(nx, ny, k);
        }
      }
    }
    int res = 0;  // 未被保护格子数目
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          ++res;
        }
      }
    }
    return res;
  }
};
