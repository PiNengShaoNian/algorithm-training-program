export function minDistance(word1: string, word2: string): number {
  const n = word1.length
  const m = word2.length
  //dp[i][j]代表word1 的前i个字符构成的字串和
  //word2前j个字符构成的字串的最短编辑距离为dp[i][j]
  //其中i和j都从1开始
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
      if (word1[i - 1] === word2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1]
      } else {
        dp[i][j] =
          Math.min(
            /**
             * 考虑下面的情况
             * word1: abc
             * word2: abd
             * i = 3,并且j = 3
             * 对word1进行删除操作将字符c删除，原来word1和word2的编辑距离就等于
             * 下面两个字符串的编辑距离在加1
             * word1: ab
             * word2: abd
             * 也就是i - 1，但是j保持不变
             */
            dp[i - 1][j],
            /**
             * 考虑下面的情况
             * word1: abc
             * word2: abd
             * i = 3,并且j = 3
             * 对word1进行插入操作将字符d插入到word1末尾
             * 原来word1和word2的编辑距离就等于
             * 下面两个字符串的编辑距离在加1
             * 注意d是相同的字符他已经不用在被考虑了
             * word1: abc d  ==> abc
             * word2: ab  d  ==> ab
             * 也就是i不变，但是j减一
             */
            dp[i][j - 1],
            /**
             * 考虑下面的情况
             * word1: abc
             * word2: abd
             * i = 3,并且j = 3
             * 对word1进行替换操作将字符c替换为字符d
             * 原来word1和word2的编辑距离就等于
             * 下面两个字符串的编辑距离在加1
             * 注意d是相同的字符他已经不用在被考虑了
             * word1: ab  d  ==> ab
             * word2: ab  d  ==> ab
             * 也就是i减一，同时j也减一
             */
            dp[i - 1][j - 1]
          ) + 1
      }
    }
  }

  return dp[n][m]
}
