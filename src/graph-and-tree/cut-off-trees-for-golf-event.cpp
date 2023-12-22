class Solution {
 private:
  int rows;
  int cols;
  int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int bfs(vector<vector<int>> forest, int sx, int sy, int dx, int dy) {
    if (sx == dx && sy == dy) {
      return 0;
    }
    queue<pair<int, int>> qu;
    qu.emplace(sx, sy);
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    visited[sx][sy] = true;
    int steps = 0;
    while (qu.size()) {
      int size = qu.size();
      steps++;

      for (int i = 0; i < size; i++) {
        auto [cx, cy] = qu.front();
        qu.pop();

        for (int k = 0; k < 4; k++) {
          int new_x = cx + dirs[k][0];
          int new_y = cy + dirs[k][1];

          if (new_x < 0 || new_x >= rows || new_y < 0 || new_y >= cols) {
            continue;
          }
          if (forest[new_x][new_y] == 0 || visited[new_x][new_y]) {
            continue;
          }
          if (dx == new_x && dy == new_y) {
            return steps;
          }
          qu.emplace(new_x, new_y);
          visited[new_x][new_y] = true;
        }
      }
    }
    return -1;
  }

 public:
  int cutOffTree(vector<vector<int>> &forest) {
    vector<pair<int, int>> trees;
    rows = forest.size();
    cols = forest[0].size();
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (forest[i][j] > 1) {
          trees.emplace_back(i, j);
        }
      }
    }

    sort(trees.begin(), trees.end(),
         [&](const pair<int, int> &a, const pair<int, int> &b) -> bool {
           return forest[a.first][a.second] < forest[b.first][b.second];
         });

    int cx = 0;
    int cy = 0;
    int ans = 0;
    for (int i = 0; i < trees.size(); i++) {
      int dis = bfs(forest, cx, cy, trees[i].first, trees[i].second);
      if (dis == -1) {
        return -1;
      }
      ans += dis;
      cx = trees[i].first;
      cy = trees[i].second;
    }

    return ans;
  }
};