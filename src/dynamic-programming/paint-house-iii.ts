export function minCost(
  houses: number[],
  cost: number[][],
  _: number,
  __: number,
  target: number
): number {
  const n = houses.length
  const m = cost[0].length
  //dp[i][j][k]表示第i个房子粉刷成第j个颜色，并且当前一共有k个街区的最小费用
  const dp: number[][][] = Array.from({ length: n }, () =>
    Array.from({ length: m }, () =>
      Array.from<number>({ length: target }).fill(Infinity)
    )
  )
  for (let i = 0; i < houses.length; ++i) {
    --houses[i]
  }

  for (let i = 0; i < n; ++i) {
    for (let j = 0; j < m; ++j) {
      if (houses[i] !== -1 && houses[i] !== j) continue

      for (let k = 0; k < target; ++k) {
        for (let j0 = 0; j0 < m; ++j0) {
          if (j === j0) {
            if (i === 0) {
              if (k === 0) {
                dp[i][j][k] = 0
              }
            } else {
              dp[i][j][k] = Math.min(dp[i][j][k], dp[i - 1][j][k])
            }
          } else if (i > 0 && k > 0) {
            dp[i][j][k] = Math.min(dp[i][j][k], dp[i - 1][j0][k - 1])
          }
        }

        if (houses[i] === -1 && isFinite(dp[i][j][k])) {
          dp[i][j][k] += cost[i][j]
        }
      }
    }
  }

  let ans = Infinity

  for (let i = 0; i < m; ++i) {
    ans = Math.min(ans, dp[n - 1][i][target - 1])
  }

  return isFinite(ans) ? ans : -1
}
