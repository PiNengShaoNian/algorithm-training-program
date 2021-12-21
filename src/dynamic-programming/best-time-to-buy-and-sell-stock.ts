export function maxProfit(prices: number[]): number {
  let ans = 0
  let lowestPrice = prices[0]

  for (let i = 1; i < prices.length; ++i) {
    ans = Math.max(ans, prices[i] - lowestPrice)
    lowestPrice = Math.min(lowestPrice, prices[i])
  }

  return ans
}

export function maxProfit1(prices: number[]): number {
  //dp[i][0]表示在第i天不持有股票的最大收益
  //dp[i][1]表示在第i天持有股票的最大收益
  const dp: number[][] = []
  const n = prices.length
  for (let i = 0; i < n; ++i) {
    dp[i] = []
  }

  dp[0][0] = 0
  dp[0][1] = -prices[0]
  for (let i = 1; i < n; ++i) {
    dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i])
    dp[i][1] = Math.max(dp[i - 1][1], -prices[i])
  }

  return Math.max(dp[n - 1][0], dp[n - 1][1])
}
