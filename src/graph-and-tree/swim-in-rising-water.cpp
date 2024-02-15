vector<vector<int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int N;
class Solution {
 public:
  int swimInWater(vector<vector<int>> &grid) {
    N = grid.size();
    // 用二分查找找出一个最小的水位可以使人能从左上角直接游到右下角
    int left = 0;
    int right = N * N - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      vector<vector<bool>> visited(N, vector<bool>(N, false));
      // 尝试使用该水位能否联通左上角到右下角
      if (grid[0][0] <= mid && dfs(grid, 0, 0, visited, mid)) {
        // 能连接，尝试查找是否还有更低满足条件的水位
        right = mid;
      } else {
        // 不能连接到更大的范围查找
        left = mid + 1;
      }
    }
    return left;
  }

 private:
  bool dfs(vector<vector<int>> &grid, int x, int y,
           vector<vector<bool>> &visited, int threshold) {
    visited[x][y] = true;
    for (auto &&direction : DIRECTIONS) {
      int newX = x + direction[0];
      int newY = y + direction[1];
      if (inArea(newX, newY) && !visited[newX][newY] &&
          grid[newX][newY] <= threshold) {
        if (newX == N - 1 && newY == N - 1) {
          return true;
        }

        if (dfs(grid, newX, newY, visited, threshold)) {
          return true;
        }
      }
    }
    return false;
  }

  bool inArea(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; }
};