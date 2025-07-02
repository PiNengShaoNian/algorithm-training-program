class Solution {
 public:
  int possibleStringCount(string word, int k) {
    int n = word.size();
    if (n < k) {  // 无法满足要求
      return 0;
    }

    const int MOD = 1'000'000'007;
    vector<int> cnts;
    long long ans = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt++;
      if (i == n - 1 || word[i] != word[i + 1]) {
        // 如果 cnt = 1，这组字符串必选，无需参与计算
        if (cnt > 1) {
          if (k > 0) {
            cnts.push_back(cnt - 1);
          }
          ans = ans * cnt % MOD;
        }
        k--;  // 注意这里把 k 减小了
        cnt = 0;
      }
    }

    if (k <= 0) {
      return ans;
    }

    int m = cnts.size();
    vector f(m + 1, vector<int>(k));
    ranges::fill(f[0], 1);
    vector<int> s(k + 1);
    for (int i = 0; i < m; i++) {
      // 计算 f[i] 的前缀和数组 s
      for (int j = 0; j < k; j++) {
        s[j + 1] = (s[j] + f[i][j]) % MOD;
      }
      // 计算子数组和
      for (int j = 0; j < k; j++) {
        f[i + 1][j] = (s[j + 1] - s[max(j - cnts[i], 0)]) % MOD;
      }
    }

    return (ans - f[m][k - 1] + MOD) % MOD;  // 保证结果非负
  }
};