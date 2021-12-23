export function minimumDeleteSum(s1: string, s2: string): number {
  //这题我们转换思路去求最大的公共子序列和
  //然后答案就等于两个字符串的和减去两倍的最大的公共子序列和
  let totalSum = 0
  const n = s1.length
  const m = s2.length

  for (let i = 0; i < n; ++i) {
    totalSum += s1.charCodeAt(i)
  }

  for (let i = 0; i < m; ++i) {
    totalSum += s2.charCodeAt(i)
  }

  let maxCommonSum = 0
  // dp[i][j]表示s1中前i个字符构成的字串和s2中前j个字符构成的字串的最大的公共
  // 子序列和其中i和j都是从1开始的
  let dp: number[][] = Array.from({ length: n + 1 }, () =>
    Array.from<number>({ length: m + 1 }).fill(0)
  )

  for (let i = 1; i <= n; ++i) {
    for (let j = 1; j <= m; ++j) {
      if (s1[i - 1] === s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + s1.charCodeAt(i - 1)
      } else {
        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1])
      }

      maxCommonSum = Math.max(maxCommonSum, dp[i][j])
    }
  }

  return totalSum - 2 * maxCommonSum
}

export function minimumDeleteSum1(s1: string, s2: string): number {
  const n = s1.length
  const m = s2.length
  // dp[i][j]表示s1中前i个字符构成的字串和s2中前j个字符构成的字串的
  // 需要删除的最小的ASCII和
  const dp: number[][] = Array.from({ length: n + 1 }, () =>
    Array.from<number>({ length: m + 1 }).fill(0)
  )

  for (let i = 1; i <= n; ++i) {
    dp[i][0] = dp[i - 1][0] + s1.charCodeAt(i - 1)
  }

  for (let i = 1; i <= m; ++i) {
    dp[0][i] = dp[0][i - 1] + s2.charCodeAt(i - 1)
  }

  for (let i = 1; i <= n; ++i) {
    for (let j = 1; j <= m; ++j) {
      dp[i][j] =
        s1[i - 1] === s2[j - 1]
          ? dp[i - 1][j - 1]
          : Math.min(
              dp[i - 1][j] + s1.charCodeAt(i - 1),
              dp[i][j - 1] + s2.charCodeAt(j - 1)
            )
    }
  }

  return dp[n][m]
}
