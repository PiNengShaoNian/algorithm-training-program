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

export function longestPalindromeSubseq1(s: string): number {
  //dp[i][j]代表s[i,j]所代表的字串中包含的最长回文子序列长度为dp[i][j]
  const dp: number[][] = []
  const n = s.length

  for (let i = 0; i < n; ++i) {
    dp[i] = Array.from<number>({ length: n }).fill(0)
  }

  for (let i = n - 1; i >= 0; --i) {
    dp[i][i] = 1
    for (let j = i + 1; j < n; ++j) {
      if (s[i] === s[j]) {
        dp[i][j] = dp[i + 1][j - 1] + 2
      } else {
        dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1])
      }
    }
  }

  return dp[0][n - 1]
}
