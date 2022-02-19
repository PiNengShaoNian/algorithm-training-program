function strangePrinter(s: string): number {
  //dp[i][j]为s[i:j]区间内的字符串需要的最少打印次数
  const dp: number[][] = []
  const n = s.length

  for (let i = 0; i < n; ++i) {
    dp[i] = []
  }

  for (let i = n - 1; i >= 0; --i) {
    dp[i][i] = 1
    for (let j = i + 1; j < n; ++j) {
      let min = Infinity
      if (s[i] === s[j]) {
        dp[i][j] = dp[i][j - 1]
        continue
      }
      for (let k = i; k < j; ++k) {
        min = Math.min(min, dp[i][k] + dp[k + 1][j])
      }
      dp[i][j] = min
    }
  }

  return dp[0][n - 1]
}
