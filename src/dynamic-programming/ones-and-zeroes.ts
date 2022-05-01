function findMaxForm(strs: string[], m: number, n: number): number {
  //二维0-1背包问题
  //dp[i][j][k]表示只考虑前i个字符串，使用了j个0，k个1的情况下能得到的最大字符串数量
  const dp: number[][][] = []
  const len = strs.length
  for (let i = 0; i <= len; ++i) {
    dp[i] = []
    for (let j = 0; j <= m; ++j) {
      dp[i][j] = Array.from<number>({ length: n + 1 }).fill(0)
    }
  }

  const getZerosAndOnes = (str: string): number[] => {
    let ans = [0, 0]
    const n = str.length
    for (let i = 0; i < n; ++i) {
      ++ans[str[i] === '0' ? 0 : 1]
    }

    return ans
  }

  for (let i = 1; i <= len; ++i) {
    const [zeros, ones] = getZerosAndOnes(strs[i - 1])
    for (let j = 0; j <= m; ++j) {
      for (let k = 0; k <= n; ++k) {
        dp[i][j][k] = dp[i - 1][j][k]
        if (j >= zeros && k >= ones) {
          dp[i][j][k] = Math.max(
            dp[i][j][k],
            dp[i - 1][j - zeros][k - ones] + 1
          )
        }
      }
    }
  }

  return dp[len][m][n]
}
