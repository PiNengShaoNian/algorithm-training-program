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

export function minDistance1(word1: string, word2: string): number {
  const n = word1.length
  const m = word2.length
  //dp[i][j]代表word1[0,i]和word2[0,j]所代表的前缀的最小删除次数为dp[i][j]
  const dp: number[][] = []

  for (let i = 0; i <= n; ++i) {
    dp[i] = []
    dp[i][0] = i
  }

  for (let i = 0; i <= m; ++i) {
    dp[0][i] = i
  }

  for (let i = 1; i <= n; ++i) {
    for (let j = 1; j <= m; ++j) {
      //公共字符dp[i][j]等于dp[i- 1][j - 1]
      if (word1[i - 1] === word2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1]
      } else {
        dp[i][j] = Math.min(dp[i][j - 1], dp[i - 1][j]) + 1
      }
    }
  }

  return dp[n][m]
}
