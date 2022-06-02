export function numRollsToTarget(n: number, m: number, target: number): number {
  //dp[i][j]表示投出i个骰子，并且点数之和为j时的方案数
  const dp: Uint32Array[] = []

  for (let i = 0; i <= n; ++i) {
    dp[i] = new Uint32Array(1001)
  }

  for (let i = 1; i <= m; ++i) {
    //投掷出1个骰子，并且点数为i时的方案数
    dp[1][i] = 1
  }

  const MAX = n * m
  const MOD = 1e9 + 7

  //枚举投掷的骰子个数
  for (let i = 2; i <= n; ++i) {
    //枚举点数之和
    for (let j = i; j <= MAX; ++j) {
      //枚举第i次投掷出的点数
      for (let k = 1; j - k >= 0 && k <= m; ++k) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD
      }
    }
  }

  return dp[n][target]
}
