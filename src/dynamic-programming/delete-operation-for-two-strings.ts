export function minDistance(word1: string, word2: string): number {
  //用最长公共子序列的思路做题，假如word1和word2的最长公共子序列
  //长度为n那么word1和word2中需要删除的总字符就为(word1.length - n) + (word2.length - n)
  const dp: number[][] = []
  const n = word1.length
  const m = word2.length

  for (let i = 0; i <= n; ++i) {
    dp[i] = []
    dp[i][0] = 0
  }

  for (let i = 0; i <= m; ++i) {
    dp[0][i] = 0
  }

  for (let i = 1; i <= n; ++i) {
    for (let j = 1; j <= m; ++j) {
      if (word1[i - 1] === word2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1
      } else {
        dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j])
      }
    }
  }

  return word1.length + word2.length - 2 * dp[n][m]
}
