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

class UnionFind {
 public:
  UnionFind(int n) {
    data = vector<int>(n);
    for (int i = 0; i < n; i++) {
      data[i] = i;
    }
  }

  int find(int x) { return x == data[x] ? x : (data[x] = find(data[x])); }

  int isConnected(int a, int b) { return find(a) == find(b); }

  void connect(int a, int b) {
    int p1 = find(a);
    int p2 = find(b);
    if (p1 == p2) {
      return;
    }
    data[p1] = p2;
  }

 private:
  vector<int> data;
};

class Solution1 {
 public:
  int swimInWater(vector<vector<int>> &grid) {
    N = grid.size();
    int len = N * N;
    vector<int> index(len, 0);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        index[grid[i][j]] = getIndex(i, j);
      }
    }

    UnionFind unionFind(len);
    for (int i = 0; i < len; i++) {
      int x = index[i] / N;
      int y = index[i] % N;

      for (auto &&direction : DIRECTIONS) {
        int newX = x + direction[0];
        int newY = y + direction[1];
        if (inArea(newX, newY) && grid[newX][newY] <= i) {
          unionFind.connect(index[i], getIndex(newX, newY));
        }

        if (unionFind.isConnected(0, len - 1)) {
          return i;
        }
      }
    }
    return -1;
  }

 private:
  vector<vector<int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int N;

  int getIndex(int x, int y) { return x * N + y; }

  bool inArea(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; }
};

class Solution2 {
 public:
  int swimInWater(vector<vector<int>> &grid) {
    int n = grid.size();
    // 定义 cmp 结构体为 swimInWater 函数的内部类
    struct cmp {
      vector<vector<int>> &grid;                // 引用外部的局部变量 grid
      cmp(vector<vector<int>> &g) : grid(g) {}  // 构造函数初始化 grid 引用

      bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return grid[a.first][a.second] > grid[b.first][b.second];  // 小根堆
      }
    };

    // 使用自定义的比较器 cmp
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> minHeap(
        (cmp(grid)));
    minHeap.push({0, 0});
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    // distTo[i][j] 表示：到顶点 [i, j] 须要等待的最少的时间
    vector<vector<int>> distTo(n, vector<int>(n, n * n));
    distTo[0][0] = grid[0][0];

    while (!minHeap.empty()) {
      auto [x, y] = minHeap.top();
      minHeap.pop();
      if (visited[x][y]) {
        continue;
      }

      visited[x][y] = true;
      if (x == n - 1 && y == n - 1) {
        return distTo[n - 1][n - 1];
      }

      for (auto &&dir : DIRECTIONS) {
        int newX = x + dir[0];
        int newY = y + dir[1];
        if (inArea(newX, newY, n) && !visited[newX][newY] &&
            max(distTo[x][y], grid[newX][newY]) < distTo[newX][newY]) {
          distTo[newX][newY] = max(distTo[x][y], grid[newX][newY]);
          minHeap.push({newX, newY});
        }
      }
    }

    return -1;
  }

 private:
  vector<vector<int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  bool inArea(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
  }
};

class Solution {
 public:
  int n;
  int dirs[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
  vector<vector<bool>> visit;
  vector<vector<int>> grid;
  unordered_map<int, int> memo;

  int getKey(int row, int col, int maxHeight) {
    return (row << 20) | (col << 13) | maxHeight;
  }

  int dfs(int row, int col, int maxHeight) {
    if (row == n - 1 && col == n - 1) {
      return maxHeight;
    }

    int key = getKey(row, col, maxHeight);
    if (memo.count(key)) {
      return memo[key];
    }

    visit[row][col] = true;

    int ans = INT_MAX;
    for (int i = 0; i < 4; i++) {
      int newRow = dirs[i][0] + row;
      int newCol = dirs[i][1] + col;
      if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
          !visit[newRow][newCol]) {
        ans =
            min(ans, dfs(newRow, newCol, max(maxHeight, grid[newRow][newCol])));
      }
    }

    visit[row][col] = false;
    memo[key] = ans;
    return ans;
  }

  int swimInWater(vector<vector<int>> &grid) {
    int n = grid.size();
    this->n = n;
    this->grid = grid;
    this->visit = vector<vector<bool>>(n, vector<bool>(n, false));
    this->memo.clear();

    return dfs(0, 0, grid[0][0]);
  }
};