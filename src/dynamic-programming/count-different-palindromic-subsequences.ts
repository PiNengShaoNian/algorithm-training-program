function countPalindromicSubsequences(s: string): number {
  //dp[k][i][j]表示在s[i:j]区间内存在一类回文子序列他个个数，该类回文子序列满足以下条件
  //他的最左边字符p[l]和最右边字符p[r]等于字符c其中c = String.fromCharCode(k + 97)
  //也就是p[l] = p[r] = c,不难看出当i == j是dp[k][i][j] = 1 (a = {a}),
  //当j == i + 1时dp[k][i][j] = 2 (aa = {a, aa})
  //
  const dp: number[][][] = []
  const n = s.length
  const mod = 1000000007
  for (let i = 0; i < 4; ++i) {
    dp[i] = []
    for (let j = 0; j < n; ++j) {
      dp[i][j] = []
    }
  }

  for (let i = n - 1; i >= 0; --i) {
    for (let j = i; j < n; ++j) {
      for (let k = 0; k < 4; ++k) {
        const c = String.fromCharCode(97 + k)
        if (i === j) {
          //如果c不等于s[i]那么就说明该区间内没有符合条件的回文子序列，否则就
          //说明有一个满足条件的回文子序列
          dp[k][i][j] = c === s[i] ? 1 : 0
        } else if (c !== s[i]) {
          //考虑字符串ca,此时i = 0,j = 1
          //此时dp['a' - 97][1][1] = 1
          //dp['a' - 97][0][1]应该等于dp['a' - 97][1][1]
          //都是只包含一个目标子序列{a}
          //不难看出此时字符a[0]压根不会给目标子序列集合贡献答案
          //所以s[i:j]区间和s[i+1:j]区间内目标子序列的个数相同的
          dp[k][i][j] = dp[k][i + 1][j]
        } else if (c !== s[j]) {
          //原理同上
          dp[k][i][j] = dp[k][i][j - 1]
        } else {
          if (j === i + 1) {
            //aa = {a, aa}
            dp[k][i][j] = 2
          } else {
            //此时j - i > 2
            //此时目标子序列可以通过为dp[t][i + 1][j - 1] (其中 0 <= t < 4)
            //中的每个子序列包上c获得，不难看出前面构建出来的子序列长度至少为3
            //应为j - i > 2,那么j - 1 - (i + 1) >= 1,而且还要再在两边都包上c
            //所以还得在加上长度小于3的目标子序列,小于3的目标子序列个数是固定的为2
            //应为只有{c,cc}两个子序列

            //长度小于2的目标子序列个数
            dp[k][i][j] = 2

            //累加上长度大于2的目标子序列个数
            for (let t = 0; t < 4; ++t) {
              dp[k][i][j] += dp[t][i + 1][j - 1]
              dp[k][i][j] %= mod
            }
          }
        }
      }
    }
  }

  let ans = 0

  for (let i = 0; i < 4; ++i) {
    ans += dp[i][0][n - 1]
    ans %= mod
  }

  return ans
}
