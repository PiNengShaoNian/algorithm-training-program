export function maxProfit(prices: number[]): number {
  //dp[i][0]表示在第i天不持有股票的最大收益
  //dp[i][1]表示在第i天持有股票的最大收益
  const dp: number[][] = []
  const n = prices.length
  dp[0] = []
  dp[0][0] = 0
  dp[0][1] = -prices[0]

  for (let i = 1; i < n; ++i) {
    dp[i] = []
    dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i])
    //和best-time-to-buy-and-sell-stock的唯一区别,因为这里可以买卖多次所以
    //dp[i][1]需要从dp[i -1][0]推导而来,而前者只可以买卖一次
    //所以dp[i][1](当前持有股票的最大收益)只与Math.max(-prices[0...i])有关
    dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] - prices[i])
  }

  return Math.max(dp[n - 1][0], dp[n - 1][1])
}
