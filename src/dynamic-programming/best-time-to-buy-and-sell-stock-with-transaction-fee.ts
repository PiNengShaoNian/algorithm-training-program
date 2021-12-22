export function maxProfit(prices: number[], fee: number): number {
  //j为0表示当前没有持有股票，为1表示当前持有股票
  //dp[i][j]表示前i天能获得的最大收益
  const dp: number[][] = []
  const n = prices.length

  for (let i = 0; i < n; ++i) {
    dp[i] = [-Infinity, -Infinity]
  }

  dp[0][0] = 0
  //买股票时还需要付小费
  dp[0][1] = -prices[0] - fee

  for (let i = 1; i < n; ++i) {
    dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i])
    dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee)
  }

  return Math.max(dp[n - 1][0], dp[n - 1][1])
}
