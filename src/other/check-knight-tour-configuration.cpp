class Solution {
 public:
  bool checkValidGrid(vector<vector<int>>& grid) {
    if (grid[0][0] != 0) {
      return false;
    }

    int n = grid.size();
    vector<pair<int, int>> path(n * n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        path[grid[i][j]] = {i, j};
      }
    }

    pair<int, int> cur = path[0];
    for (int i = 1; i < n * n; i++) {
      pair<int, int> next = path[i];
      int diff = abs(cur.first - next.first) + abs(cur.second - next.second);
      if (diff != 3 || cur.first == next.first || cur.second == next.second) {
        return false;
      }
      cur = next;
    }

    return true;
  }
};