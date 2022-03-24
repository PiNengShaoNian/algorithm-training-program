export function profitableSchemes(
  n: number,
  minProfit: number,
  group: number[],
  profits: number[]
): number {
  //dp[i][j][k]为在前i件工作中选取，共j个人参与，利润至少为k的方案数其中i从1开始
  const dp: number[][][] = []
  const len = group.length
  const MOD = 1e9 + 7
  for (let i = 0; i <= len; ++i) {
    dp[i] = []
    for (let j = 0; j <= n; ++j) {
      dp[i][j] = Array.from<number>({ length: minProfit + 1 }).fill(0)
    }
  }

  dp[0][0][0] = 1

  for (let i = 1; i <= len; ++i) {
    const member = group[i - 1]
    const profit = profits[i - 1]
    for (let j = 0; j <= n; ++j) {
      for (let k = 0; k <= minProfit; ++k) {
        if (j < member) {
          dp[i][j][k] = dp[i - 1][j][k]
        } else {
          dp[i][j][k] =
            (dp[i - 1][j][k] + dp[i - 1][j - member][Math.max(0, k - profit)]) %
            MOD
        }
      }
    }
  }

  let ans = 0

  for (let i = 0; i <= n; ++i) {
    ans = (ans + dp[len][i][minProfit]) % MOD
  }

  return ans
}
