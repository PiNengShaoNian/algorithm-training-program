class Solution {
 private:
  // T[i][j]表示当i和j为底部字母时它的顶部字母所有可能的集合
  int T[7][7];
  unordered_set<long long> seen;

 public:
  bool pyramidTransition(string bottom, vector<string>& allowed) {
    memset(T, 0, sizeof(T));
    seen.clear();
    for (auto& s : allowed) {
      T[s[0] - 'A'][s[1] - 'A'] |= 1 << (s[2] - 'A');
    }

    int N = bottom.size();
    // A[i][j]表示第i行金字塔的第j位选择的字母
    vector<vector<int>> A(N, vector<int>(N));
    int t = 0;
    for (char c : bottom) {
      A[N - 1][t++] = c - 'A';
    }
    return solve(A, 0, N - 1, 0);
  }

  // A[i] - 第i行金字塔
  // R    - 当前行金字塔字母的选择情况(用一个8进制数保存)
  // N    - 当前行的下一行(方便从改行枚举出状态,
  // 比如当前在枚举第0行的状态那么此时N就为1) i    -
  // 当时要枚举此行中的第几位的状态
  bool solve(vector<vector<int>>& A, long long R, int N, int i) {
    if (N == 1 && i == 1) {  // 如果成功枚举完整个金字塔，返回true
      return true;
    } else if (i == N) {
      // 当前行总共有N - 1位，此时已经完成了改行所有位的枚举，开始枚举更上面的行
      if (seen.contains(R)) {
        // 之前已经走过这条路但是没有走通，再次遇到它时直接返回false
        return false;
      }

      return solve(A, 0, N - 1, 0);
    } else {
      // 获得改行第i位总共所有可能选择的集合
      int w = T[A[N][i]][A[N][i + 1]];
      // 枚举集合中的每个元素
      for (int b = 0; b < 7; b++) {
        if (((w >> b) & 1) != 0) {
          // 选择第i位为字母b
          A[N - 1][i] = b;
          // 继续枚举同一行中下一位的状态
          if (solve(A, R * 8 + (b + 1), N, i + 1)) {
            return true;
          }
        }
      }
      return false;
    }
  }
};

class Solution {
 public:
  bool pyramidTransition(string bottom, vector<string>& allowed) {
    string groups[6][6]{};
    for (auto& s : allowed) {
      groups[s[0] - 'A'][s[1] - 'A'] += s[2];
    }

    int n = bottom.size();
    vector<string> pyramid(n);
    for (int i = 0; i < n - 1; i++) {
      pyramid[i].resize(i + 1);
    }
    pyramid[n - 1] = bottom;

    // 现在准备填 (i, j) 这个格子
    // 返回继续填能否填完所有格子（从下往上填，每行从左到右填）
    auto dfs = [&](this auto&& dfs, int i, int j) -> bool {
      if (i < 0) {  // 所有格子都已填完
        return true;
      }

      if (j == i + 1) {        // i 行已填完
        return dfs(i - 1, 0);  // 开始填 i-1 行
      }

      // 枚举 (i, j) 填什么字母
      // 这取决于 (i+1, j) 和 (i+1, j+1) 填的字母
      for (char top :
           groups[pyramid[i + 1][j] - 'A'][pyramid[i + 1][j + 1] - 'A']) {
        pyramid[i][j] = top;
        if (dfs(i, j + 1)) {
          return true;
        }
      }
      return false;
    };

    // 从倒数第二行开始填
    return dfs(n - 2, 0);
  }
};