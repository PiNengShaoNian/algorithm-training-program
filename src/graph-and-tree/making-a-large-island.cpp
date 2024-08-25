const vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
 public:
  bool valid(int n, int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }

  int dfs(vector<vector<int>> &grid, int x, int y,
          vector<vector<int>> &posToIslandId, int islandId) {
    int n = grid.size();
    int ans = 1;

    for (int i = 0; i < 4; i++) {
      int newx = dirs[i][0] + x;
      int newy = dirs[i][1] + y;
      if (valid(n, newx, newy) && grid[newx][newy] == 1 &&
          posToIslandId[newx][newy] == 0) {
        posToIslandId[newx][newy] = islandId;
        ans += dfs(grid, newx, newy, posToIslandId, islandId);
      }
    }

    return ans;
  }

  int largestIsland(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<vector<int>> posToIslandId(n, vector<int>(n));
    unordered_map<int, int> islandIdToSize;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1 && posToIslandId[i][j] == 0) {
          int islandId = i * n + j + 1;
          posToIslandId[i][j] = islandId;
          islandIdToSize[islandId] = dfs(grid, i, j, posToIslandId, islandId);
          ans = max(ans, islandIdToSize[islandId]);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          unordered_set<int> connected;
          int size = 1;
          for (int k = 0; k < 4; k++) {
            int x = dirs[k][0] + i;
            int y = dirs[k][1] + j;
            if (!valid(n, x, y) || posToIslandId[x][y] == 0 ||
                connected.count(posToIslandId[x][y])) {
              continue;
            }

            size += islandIdToSize[posToIslandId[x][y]];
            connected.insert(posToIslandId[x][y]);
          }
          ans = max(ans, size);
        }
      }
    }
    return ans;
  }
};