export function integerBreak(n: number): number {
  const dp: number[] = []
  //dp[i] 表示拆分i能得到的最大乘积
  dp[1] = 1

  for (let i = 2; i <= n; ++i) {
    dp[i] = -Infinity
    for (let j = 1; j < i; ++j) {
      dp[i] = Math.max(dp[i], dp[i - j] * j, (i - j) * j)
    }
  }

  return dp[n]
}
