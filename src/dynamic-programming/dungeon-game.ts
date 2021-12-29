export function calculateMinimumHP(dungeon: number[][]): number {
  const n = dungeon.length
  const m = dungeon[0].length
  //dp[i][j]代表从坐标(i,j)走到终点需要的最小生命值
  const dp: number[][] = Array.from({ length: n + 1 }, () =>
    Array.from<number>({ length: m + 1 }).fill(Infinity)
  )

  dp[n - 1][m] = dp[n][m - 1] = 1

  for (let i = n - 1; i >= 0; --i) {
    for (let j = m - 1; j >= 0; --j) {
      const minin = Math.min(dp[i + 1][j], dp[i][j + 1])

      dp[i][j] = Math.max(minin - dungeon[i][j], 1)
    }
  }

  return dp[0][0]
}
