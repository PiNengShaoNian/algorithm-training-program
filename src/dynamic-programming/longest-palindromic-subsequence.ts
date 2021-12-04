export function longestPalindromeSubseq(s: string): number {
  //求一个字符串内的最长回文子序列，等价于去求和他自己的反转字符串
  //的最长公共子序列
  const word1 = s
  const word2 = Array.from(s).reverse().join('')

  const n = word1.length
  const dp: number[][] = []
  for (let i = 0; i <= n; ++i) {
    dp[i] = []
    dp[i][0] = 0
    dp[0][i] = 0
  }

  for (let i = 1; i <= n; ++i) {
    for (let j = 1; j <= n; ++j) {
      if (word1[i - 1] === word2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1
      } else {
        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1])
      }
    }
  }

  return dp[n][n]
}
