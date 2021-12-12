export function minCost(costs: number[][]): number {
  //dp[i][0]粉刷完0-i个房子，并且i房子被染成红色的最低成本为dp[i][0]
  const dp: number[][] = []
  const n = costs.length
  for (let i = 0; i < n; ++i) {
    dp[i] = []
  }
  dp[0][0] = costs[0][0]
  dp[0][1] = costs[0][1]
  dp[0][2] = costs[0][2]

  for (let i = 1; i < n; ++i) {
    dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0]
    dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1]
    dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2]
  }

  return Math.min(dp[n - 1][0], dp[n - 1][1], dp[n - 1][2])
}
