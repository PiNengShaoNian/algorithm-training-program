//自顶向下dp
export function numDecodings(s: string): number {
  const memo: number[] = []

  //core(n)代表s[n,s.length - 1]区间内的解码方法个数为core(n)
  //不难看出core(i) = core(i + 1)
  //当下一个字符和当前字符能映射一个字符时还要加上core(i + 2)
  const core = (n: number): number => {
    let res = 0

    if (memo[n] !== undefined) return memo[n]

    if (n === s.length) return 1

    if (s[n] === '0') return 0

    res += core(n + 1)

    if (n + 1 < s.length && s.substr(n, 2) <= '26') {
      res += core(n + 2)
    }

    return (memo[n] = res)
  }

  return core(0)
}

//自底向上递推dp
export function numDecodings1(s: string): number {
  if (s[0] === '0') return 0

  const n = s.length
  //dp[i]表示s[i,n]区间个字符的解码方法个数为dp[i]
  //考虑到已'0'开头的串的解码方式为0我们可以从后往前递推
  const dp: number[] = []
  dp[n] = 1

  for (let i = n - 1; i >= 0; --i) {
    //以'0'开头的串解码方式为0
    if (s[i] === '0') {
      dp[i] = 0
    } else {
      dp[i] = dp[i + 1]

      if (i + 1 < n && s[i] + s[i + 1] <= '26') {
        dp[i] += dp[i + 2]
      }
    }
  }

  return dp[0]
}
