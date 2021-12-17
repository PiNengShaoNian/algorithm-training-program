export function minDistance(houses: number[], k: number): number {
  houses.sort((a, b) => a - b)
  const n = houses.length

  //cost[i][j]表示 houses[i,j]区间内的房子分配一个邮箱的距离总和
  const cost: number[][] = []

  for (let i = 0; i < n; ++i) {
    cost[i] = []
    for (let j = 0; j < n; ++j) {
      cost[i][j] = 0
    }
  }

  for (let i = n - 1; i >= 0; --i) {
    for (let j = i + 1; j < n; ++j) {
      cost[i][j] = cost[i + 1][j - 1] + houses[j] - houses[i]
    }
  }

  //dp[i][k]表示前i个房子(i从0开始)分配k个邮箱(k从1开始)最小的距离总和
  const dp: number[][] = []

  for (let i = 0; i < n; ++i) {
    dp[i] = []
    for (let j = 0; j <= k; ++j) {
      dp[i][j] = Infinity
    }
  }

  for (let i = 0; i < n; ++i) {
    dp[i][1] = cost[0][i]
    for (let j = 2; j <= k && j <= i + 1; ++j) {
      for (let i0 = 0; i0 < i; ++i0) {
        dp[i][j] = Math.min(dp[i][j], dp[i0][j - 1] + cost[i0 + 1][i])
      }
    }
  }

  return dp[n - 1][k]
}
