export function checkRecord(n: number): number {
  //dp[i][j][k]表示前i天在缺席j天，最后几天连续迟到j天的情况下可以获取奖励的情况数量
  //为了保障只枚举有效装填其中 0 <= j <= 1并且 0 <= k <= 2
  const dp: number[][][] = []
  const MOD = 1e9 + 7

  for (let i = 0; i <= n; ++i) {
    dp[i] = [
      [0, 0, 0],
      [0, 0, 0],
    ]
  }

  dp[0][0][0] = 1

  for (let i = 1; i <= n; ++i) {
    for (let j = 0; j <= 1; ++j) {
      for (let k = 0; k <= 2; ++k) {
        //第i天状态为P
        dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD

        if (k - 1 >= 0) {
          //第i天状态为L
          dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD
        }

        //第i天状态为A
        if (j - 1 >= 0) {
          dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j - 1][k]) % MOD
        }
      }
    }
  }

  let ans = 0

  for (let j = 0; j <= 1; ++j) {
    for (let k = 0; k <= 2; ++k) {
      ans = (ans + dp[n][j][k]) % MOD
    }
  }

  return ans
}
