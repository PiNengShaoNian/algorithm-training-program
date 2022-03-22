export function change(amount: number, coins: number[]): number {
  //dp[i]表示，共有dp[i]种硬币的组合和为金额i
  const dp: number[] = Array.from<number>({ length: amount + 1 }).fill(0)
  //要组成金额0，那就什么都不选,共一种组合
  dp[0] = 1

  for (const coin of coins) {
    for (let i = coin; i <= amount; ++i) {
      dp[i] += dp[i - coin]
    }
  }

  return dp[amount]
}
