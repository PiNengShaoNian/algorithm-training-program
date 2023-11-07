class Solution {
 public:
  bool makesquare(vector<int>& matchsticks) {
    int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (totalLen % 4 != 0) {
      return false;
    }
    int len = totalLen / 4;
    int n = matchsticks.size();
    // 依次选取火柴填充四个边，一个边满了开始填充下个边
    // s: 火柴的选项状态s的第i为1表示第i个火柴被选取了，为0表示没被选取
    // dp[s]表示当前火柴的选取状态时当前填充的边的长度为多少
    vector<int> dp(1 << n, -1);
    dp[0] = 0;
    for (int s = 1; s < (1 << n); s++) {
      for (int k = 0; k < n; k++) {
        // 选取一个前驱
        if ((s & (1 << k)) == 0) {
          continue;
        }

        int s1 = s & ~(1 << k);
        // 判断是否为合法的前驱状态
        if (dp[s1] >= 0 && (dp[s1] + matchsticks[k] <= len)) {
          dp[s] = (dp[s1] + matchsticks[k]) % len;
          break;
        }
      }
    }
    return dp[(1 << n) - 1] == 0;
  }
};