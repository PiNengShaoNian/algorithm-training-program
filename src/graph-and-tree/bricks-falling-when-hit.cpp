class UnionFind {
 private:
  vector<int> parent;
  vector<int> size;

 public:
  UnionFind(int n) {
    parent = vector<int>(n);
    size = vector<int>(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int find(int x) { return x == parent[x] ? x : (x = find(parent[x])); }

  void connect(int x, int y) {
    int p1 = find(x);
    int p2 = find(y);
    if (p1 == p2) {
      return;
    }
    parent[p1] = p2;
    size[p2] += size[p1];
  }

  int getSize(int x) { return size[find(x)]; }
};

class Solution {
 public:
  int rows;
  int cols;
  vector<vector<int>> DIRECTIONS = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    vector<vector<int>> copy = grid;
    vector<int> ans(hits.size());
    rows = grid.size();
    cols = grid[0].size();
    // 把房顶设置为一个特殊的节点，也就是size
    int size = rows * cols;
    UnionFind uf(size + 1);

    // 逆向思维求解，先去除所有hits，然后又逆序加回来
    for (int i = 0; i < hits.size(); i++) {
      copy[hits[i][0]][hits[i][1]] = 0;
    }

    for (int i = 0; i < cols; i++) {
      if (copy[0][i] == 1) {
        uf.connect(i, size);
      }
    }

    for (int i = 1; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (copy[i][j] == 1) {
          if (copy[i - 1][j] == 1) {
            uf.connect(getIndex(i, j), getIndex(i - 1, j));
          }

          if (j > 0 && copy[i][j - 1] == 1) {
            uf.connect(getIndex(i, j - 1), getIndex(i, j));
          }
        }
      }
    }

    for (int i = hits.size() - 1; i >= 0; i--) {
      int x = hits[i][0];
      int y = hits[i][1];

      if (grid[x][y] == 0) {
        continue;
      }
      int origin = uf.getSize(size);

      if (x == 0) {
        uf.connect(y, size);
      }
      for (auto&& dir : DIRECTIONS) {
        int newX = x + dir[0];
        int newY = y + dir[1];
        if (inArea(newX, newY) && copy[newX][newY] == 1) {
          uf.connect(getIndex(x, y), getIndex(newX, newY));
        }
      }
      int current = uf.getSize(size);
      ans[i] = max(0, current - origin - 1);
      copy[x][y] = 1;
    }

    return ans;
  }

  int getIndex(int x, int y) { return x * cols + y; }

  bool inArea(int x, int y) { return x >= 0 && x < rows && y >= 0 && y < cols; }
};