function minPathSum(grid: number[][]): number {
  //dp[i][j]为从坐标(0,0)走到(i,j)的最小路径和
  const dp: number[][] = [[]]
  const n = grid.length
  const m = grid[0].length
  dp[0][0] = grid[0][0]
  for (let i = 1; i < n; ++i) {
    dp[i] = []
    dp[i][0] = grid[i][0] + dp[i - 1][0]
  }

  for (let i = 1; i < m; ++i) {
    dp[0][i] = grid[0][i] + dp[0][i - 1]
  }

  for (let i = 1; i < n; ++i) {
    for (let j = 1; j < m; ++j) {
      dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
    }
  }

  return dp[n - 1][m - 1]
}
