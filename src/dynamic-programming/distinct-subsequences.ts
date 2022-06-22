//记忆化搜索解法
export function numDistinct(s: string, t: string): number {
  //原问题的的意思就是从s中挑出t.length个字符组成t，总共又几种挑法
  const memo: number[][] = Array.from({ length: s.length }, () => [])
  //Impl(i,j)的意思是从s的前i个字符组成的字串s[0:i]
  //挑出j个字符能组成t[0:j],总共有Impl(i,j)个挑法
  const Impl = (i: number, j: number): number => {
    //进行适当的剪枝，如果s[0:i]的长度小于t[0:j]，先然不够挑出足够的字符构成t[0:j]
    if (i < j) return 0
    //t[0:j]为空串,只有一种挑法，选择什么都不挑
    if (j < 0) return 1

    if (typeof memo[i][j] === 'number') return memo[i][j]

    //如果两个字串的末尾字符相等那么可以选择挑出s[i]作为候选字符，将问题规模
    //缩小到Impl(i - 1,j - 1)或者选择不挑问题就变成Impl(i - 1, j)
    if (s[i] === t[j]) {
      return (memo[i][j] = Impl(i - 1, j - 1) + Impl(i - 1, j))
    } else {
      return (memo[i][j] = Impl(i - 1, j))
    }
  }

  return Impl(s.length - 1, t.length - 1)
}

//根据上面的思路我们可以写出自底向上的递推解法
export function numDistinct1(s: string, t: string): number {
  const n = s.length
  const m = t.length
  const dp: number[][] = []

  for (let i = 0; i <= n; ++i) {
    dp[i] = []
    dp[i][0] = 1
  }

  for (let i = 0; i <= m; ++i) {
    dp[0][i] = 0
  }
  dp[0][0] = 1

  for (let i = 1; i <= n; ++i) {
    for (let j = 1; j <= m; ++j) {
      if (s[i - 1] === t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
      } else {
        dp[i][j] = dp[i - 1][j]
      }
    }
  }

  return dp[n][m]
}
