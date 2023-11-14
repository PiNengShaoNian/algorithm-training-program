class Solution {
 public:
  int findRotateSteps(string ring, string key) {
    int n = ring.size();
    int m = key.size();
    // 存储一个ring中的字符他出现的所有位置
    vector<int> pos[26];
    for (int i = 0; i < n; i++) {
      pos[ring[i] - 'a'].push_back(i);
    }
    // dp[i][j] 表示从前往后拼写出 key 的第 i 个字符，
    // ring 的第 j 个字符与 12:00 方向对齐的最少步数（下标均从 0 开始）
    vector<vector<int>> dp(m, vector<int>(n, 0x3f3f3f3f));
    for (auto &i : pos[key[0] - 'a']) {
      dp[0][i] = min(i, n - i) + 1;
    }

    for (int i = 1; i < m; i++) {
      // 枚举当前key字符在ring中可能出现的位置
      for (auto &j : pos[key[i] - 'a']) {
        // 枚举key之前字符在ring中的位置
        for (auto &k : pos[key[i - 1] - 'a']) {
          dp[i][j] =
              min(dp[i][j], dp[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
        }
      }
    }
    return *min_element(dp[m - 1].begin(), dp[m - 1].end());
  }
};