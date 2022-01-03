export function maximalSquare(matrix: string[][]): number {
  //dp[i][j]表示以matrix[i][j]为右下角的矩形中，边长的最大值为dp[i][j]
  const dp: number[][] = []
  let ans = 0
  const n = matrix.length
  const m = matrix[0].length

  for (let i = 0; i < n; ++i) {
    dp[i] = []
    dp[i][0] = matrix[i][0] === '1' ? 1 : 0
    ans = Math.max(ans, dp[i][0])
  }

  for (let i = 0; i < m; ++i) {
    dp[0][i] = matrix[0][i] === '1' ? 1 : 0
    ans = Math.max(ans, dp[0][i])
  }

  for (let i = 1; i < n; ++i) {
    for (let j = 1; j < m; ++j) {
      if (matrix[i][j] === '1') {
        dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
      } else {
        dp[i][j] = 0
      }
      ans = Math.max(ans, dp[i][j])
    }
  }

  return ans * ans
}
