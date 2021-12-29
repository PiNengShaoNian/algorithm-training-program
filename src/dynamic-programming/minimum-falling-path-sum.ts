function minFallingPathSum(matrix: number[][]): number {
  const n = matrix.length
  const m = matrix.length
  //dp[i][j]代表从最顶层，下降到matrix[i][j]的最小值为dp[i][j]
  const dp: number[][] = []
  for (let i = 0; i < n; ++i) {
    dp[i] = []
  }
  for (let i = 0; i < m; ++i) {
    dp[0][i] = matrix[0][i]
  }

  for (let i = 1; i < n; ++i) {
    for (let j = 0; j < m; ++j) {
      dp[i][j] =
        Math.min(
          dp[i - 1][j - 1] ?? Infinity,
          dp[i - 1][j],
          dp[i - 1][j + 1] ?? Infinity
        ) + matrix[i][j]
    }
  }

  let ans = Infinity
  for (let i = 0; i < m; ++i) {
    ans = Math.min(ans, dp[n - 1][i])
  }

  return ans
}
