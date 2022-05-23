export function uniquePathsWithObstacles(obstacleGrid: number[][]): number {
  const rows = obstacleGrid.length
  const cols = obstacleGrid[0].length
  const dp: number[][] = []
  for (let i = 0; i < rows; ++i) {
    dp[i] = []
  }

  for (let row = 0; row < rows; ++row) {
    for (let col = 0; col < cols; ++col) {
      if (obstacleGrid[row][col] === 1) {
        dp[row][col] = 0
      } else if (row === 0 && col === 0) {
        dp[row][col] = 1
      } else if (row === 0) {
        dp[row][col] = dp[row][col - 1]
      } else if (col === 0) {
        dp[row][col] = dp[row - 1][col]
      } else {
        dp[row][col] = dp[row - 1][col] + dp[row][col - 1]
      }
    }
  }

  return dp[rows - 1][cols - 1]
}
