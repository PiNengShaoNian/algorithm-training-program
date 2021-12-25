export function isMatch(s: string, p: string): boolean {
  //dp[i][j]为true表示s中前i个字符构成的子串和p中前j个字符构成的模式串
  //能够匹配，为false则表示不能匹配,其中i和j都从1开始，为0时表示为空串
  const dp: boolean[][] = []
  const n = s.length
  const m = p.length
  s = ' ' + s
  p = ' ' + p

  for (let i = 0; i <= n; ++i) {
    dp[i] = []
  }

  dp[0][0] = true
  //连续的x*x*x*模式串总是能匹配空字符串,应为星号可以选择什么都不匹配
  for (let i = 2; i <= m && p[i] === '*'; i += 2) dp[0][i] = true

  for (let i = 1; i <= n; ++i) {
    for (let j = 1; j <= m; ++j) {
      if (p[j] === '.') {
        dp[i][j] = dp[i - 1][j - 1]
      } else if (p[j] === '*') {
        //星号选择什么都不匹配
        dp[i][j] = dp[i][j - 2]
        if (p[j - 1] === s[i] || p[j - 1] === '.') {
          //星号选择匹配一个s[i]字符
          dp[i][j] ||= dp[i - 1][j]
        }
      } else {
        dp[i][j] = dp[i - 1][j - 1] && s[i] === p[j]
      }
    }
  }

  return !!dp[n][m]
}
