export function maxProfit(prices: number[]): number {
  //j为0表示当前没有持有股票，1表示持有股票
  //k为0表示当前没有处于冷冻期，为1表示处于冷冻期
  //dp[i][j][k]表示前i天能取的的最大收益,i从0开始
  const dp: number[][][] = []
  const n = prices.length

  for (let i = 0; i < n; ++i) {
    dp[i] = [
      [-Infinity, -Infinity],
      [-Infinity, -Infinity],
    ]
  }

  dp[0][0][0] = 0
  dp[0][1][0] = -prices[0]

  for (let i = 1; i < n; ++i) {
    for (let j = 0; j <= 1; ++j) {
      dp[i][j][0] = Math.max(dp[i - 1][j][0], dp[i - 1][j][1])
      dp[i][1][0] = Math.max(dp[i][1][0], dp[i - 1][0][0] - prices[i])
      dp[i][0][1] = Math.max(dp[i][0][1], dp[i - 1][1][0] + prices[i])
    }
  }

  return Math.max(dp[n - 1][1][0], dp[n - 1][0][0], dp[n - 1][0][1])
}
