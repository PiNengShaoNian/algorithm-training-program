class Solution {
 public:
  bool checkValidString(string s) {
    int n = s.size();
    // dp[i][j]表示s[i:j]范围内的字串是否是合法符号串
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // 初始化长度为1的合法串
    for (int i = 0; i < n; i++) {
      dp[i][i] = s[i] == '*';
    }

    // 初始化长度为2的合法串
    for (int i = 1; i < n; i++) {
      int c1 = s[i - 1];
      int c2 = s[i];
      dp[i - 1][i] = (c1 == '*' || c1 == '(') && (c2 == '*' || c2 == ')');
    }

    // 枚举串的起始位置
    for (int i = n - 3; i >= 0; i--) {
      int c1 = s[i];
      // 枚举串的结束位置
      for (int j = i + 2; j < n; j++) {
        int c2 = s[j];
        // 如果边缘的两个字符能够互相配对，则s[i:j]是否为合法括号串取决于dp[i+1][j-1]
        if ((c1 == '(' || c1 == '*') && (c2 == '*' || c2 == ')')) {
          dp[i][j] = dp[i + 1][j - 1];
        }

        // 如果该串是由两个合法串拼接而成则它也是个合法串
        for (int k = i; k < j && !dp[i][j]; k++) {
          dp[i][j] = dp[i][k] && dp[k + 1][j];
        }
      }
    }

    return dp[0][n - 1];
  }
};