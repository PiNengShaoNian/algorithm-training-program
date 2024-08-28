class Solution {
 public:
  static constexpr int inf = 0x3f3f3f3f;
  int minimumSubstringsInPartition(string s) {
    int n = s.size();
    // dp[i]表示已i结尾的字符串能最少分成几个平衡字符串
    vector<int> dp(n + 1, inf);
    // 记录每个字符出现的个数
    unordered_map<char, int> occ_cnt;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      int max_cnt = 0;
      occ_cnt.clear();
      for (int j = i; j >= 1; j--) {
        occ_cnt[s[j - 1]]++;
        max_cnt = max(max_cnt, occ_cnt[s[j - 1]]);
        if (max_cnt * occ_cnt.size() == (i - j + 1) && dp[j - 1] != inf) {
          // s[j:i]这段字符串是平衡字符串，符合状态转移的条件
          dp[i] = min(dp[i], dp[j - 1] + 1);
        }
      }
    }
    return dp[n];
  }
};