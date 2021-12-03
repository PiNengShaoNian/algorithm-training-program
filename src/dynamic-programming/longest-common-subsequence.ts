export function longestCommonSubsequence(text1: string, text2: string): number {
  //dp[i][j]代表text1[0,i - 1]和text2[0,j-1]的最长公共子序列长度为dp[i][j]
  const dp: number[][] = []
  const n = text1.length
  const m = text2.length

  for (let i = 0; i <= n; ++i) {
    dp[i] = []
    //text2长度为零是lcs的长度为0
    dp[i][0] = 0
  }

  for (let i = 0; i <= m; ++i) {
    //text1长度为零是lcs的长度为0
    dp[0][i] = 0
  }

  for (let i = 1; i <= n; ++i) {
    for (let j = 1; j <= m; ++j) {
      if (text1[i - 1] === text2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1
      } else {
        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1])
      }
    }
  }

  return dp[n][m]
}
