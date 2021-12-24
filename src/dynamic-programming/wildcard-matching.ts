function isMatch(s: string, p: string): boolean {
  const n = s.length
  const m = p.length

  //dp[i][j]为true表示s中前i个字符构成的子串和p中前j个字符构成的模式串
  //能够匹配，为false则表示不能匹配,其中i和j都从1开始，为0时表示为空串
  const dp: boolean[][] = []

  for (let i = 0; i <= n; ++i) {
    dp[i] = []
  }

  //空字符串和空模式串匹配
  dp[0][0] = true
  //开头连续的*好能和空字符串匹配
  for (let i = 1; i <= m && p[i - 1] === '*'; ++i) dp[0][i] = true

  for (let i = 1; i <= n; ++i) {
    for (let j = 1; j <= m; ++j) {
      if (s[i - 1] === p[j - 1] || p[j - 1] === '?') {
        //当s[i - 1]和p[j - 1]相等或者p[j - 1]等于问号时，dp[i][j]等于
        //dp[i - 1][j - 1]的匹配情况
        dp[i][j] = dp[i - 1][j - 1]
      } else if (p[j - 1] === '*') {
        dp[i][j] =
          //这个星号选择匹配若干个字符则
          // dp[i][j] = dp[i-1][j] || dp[i-2][j] || dp[i-3][j] || ...|| dp[0][j]，
          // dp[i-1][j] = dp[i-2][j] || dp[i-3][j] || ...|| dp[0][j]，
          // dp[i][j] ==> dp[i-1][j]
          //考虑如下情况
          //s = hello
          //p = he*
          //i = 5, j = 3
          //在最后一个星号选择若干字符的情况下
          //dp[5][3] = dp[5 - 1][3] || dp[5 - 2][3] || dp[5 - 3][3] || dp[5 - 4][3] || dp[5 - 5][3]
          //dp[5][3] = dp[4][3] || dp[3][3] || dp[2][3] || dp[1][3] || dp[0][3]
          //不难看出dp[2][2] = true，因为`he`是s和p的公共前缀
          //又因为dp[2][3] = dp[2 - 1][3] || dp[2 - 2][3] || dp[2][2](星号选择不匹配字符)
          //   所以dp[2][3] = true
          //同理dp[3][3],dp[4][3],dp[5][3]都为true
          dp[i - 1][j] ||
          //这个星号选择什么都不匹配，匹配结构就等于dp[i][j - 1]
          dp[i][j - 1]
      }
    }
  }

  return !!dp[n][m]
}
