//动态规划解法
function isInterleave(s1: string, s2: string, s3: string): boolean {
  const n = s1.length
  const m = s2.length

  if (n + m !== s3.length) return false

  //dp[i][j]为true表示s1的前i个字符，和s2的前j个字符能交错的组成s3的前i + j个
  //字符形成的字串，为false则表示不能组成
  const dp: boolean[][] = []

  for (let i = 0; i <= n; ++i) {
    dp[i] = []
  }

  dp[0][0] = true

  for (let i = 0; i <= n; ++i) {
    for (let j = 0; j <= m; ++j) {
      const p = i + j - 1

      if (i > 0) {
        //状态转移的正确性
        //dp[i - 1][j]是可以交错的，则有以下几种情况
        //(1). s1和s2都被分为了x组，其中组成的交错中最后一个分组属于s1
        //(2). s1和s2都被分为了x组，其中组成的交错中最后一个分组属于s2
        //(3). s1被分为了x组，s2被分为了x+1组，其中最后一个分组只能属于s2
        //(3). s1被分为了x+1组，s2被分为了x组，其中最后一个分组只能属于s1
        //如果在这里s1的第i个字符等于s3的第i + j个字符
        //dp[i-1][j]是(1)情况可以将最后一个分组扩展一个字符，仍然满足交错定义
        //dp[i-1][j]是(2)情况s1的分组个数将变为x + 1,仍然满足交错定义
        //dp[i-1][j]是(3)情况s1的分组个数将变为x + 1,仍然满足交错定义
        //dp[i-1][j]是(4)可以将最后一个分组扩展一个字符，仍然满足交错定义
        dp[i][j] ||= dp[i - 1][j] && s1[i - 1] === s3[p]
      }

      if (j > 0) {
        //这里的转移逻辑同上
        dp[i][j] ||= dp[i][j - 1] && s2[j - 1] === s3[p]
      }
    }
  }

  return dp[n][m]
}
