export function maxProfit(prices: number[]): number {
  // j为0代表没有持有股票,1代表为持有股票
  // k标识目前已经进行的交易次数
  // dp[i][j][k]截止至第i天的最大收益
  // 注意：我们在这里在每次买入股票是把交易次数加1，卖出时交易次数不变
  // 当然也可以反过来实现
  const dp: number[][][] = []
  const n = prices.length

  for (let i = 0; i < n; ++i) {
    dp[i] = [
      [-Infinity, -Infinity, -Infinity],
      [-Infinity, -Infinity, -Infinity],
    ]
  }
  dp[0][0][0] = 0
  dp[0][1][1] = -prices[0]

  for (let i = 1; i < n; ++i) {
    for (let k = 0; k <= 2; ++k) {
      if (k === 0) {
        //交易次数为0也就是说还没有买过股票，最大收益为0
        dp[i][0][k] = 0
      } else {
        //这里的逻辑和best-time-to-buy-and-sell-stock-ii差不多
        dp[i][1][k] = Math.max(dp[i - 1][0][k - 1] - prices[i], dp[i - 1][1][k])
        dp[i][0][k] = Math.max(dp[i - 1][0][k], dp[i - 1][1][k] + prices[i])
      }
    }
  }

  let ans = 0

  for (let i = 0; i <= 2; ++i) {
    ans = Math.max(ans, dp[n - 1][0][i], dp[n - 1][1][i])
  }

  return ans
}
