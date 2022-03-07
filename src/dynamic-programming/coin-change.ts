function coinChange(coins: number[], amount: number): number {
  const dp: number[] = Array.from<number>({ length: amount + 1 }).fill(Infinity)
  dp[0] = 0
  const n = coins.length

  for (let i = 1; i <= amount; ++i) {
    for (let j = 0; j < n; ++j) {
      const coin = coins[j]
      if (i >= coin) {
        dp[i] = Math.min(dp[i], dp[i - coin] + 1)
      }
    }
  }

  return isFinite(dp[amount]) ? dp[amount] : -1
}
