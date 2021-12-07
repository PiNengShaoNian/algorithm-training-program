export function minCut(s: string): number {
  const g: boolean[][] = []
  const n = s.length

  for (let i = 0; i < n; ++i) {
    g[i] = []
    for (let j = 0; j < n; ++j) {
      g[i][j] = true
    }
  }

  //用回文串分割一的思路，先预处理字符串，算出一个字串是否是回文串
  //如果s[i]和s[j]相等那么并且s[i - 1,j-1]区间所代表的字串也是回文串
  //那么s[i,j]所代表的子串也是回文串
  for (let i = n - 1; i >= 0; --i) {
    for (let j = i + 1; j < n; ++j) {
      g[i][j] = s[i] === s[j] && g[i + 1][j - 1]
    }
  }

  //dp[i]表示s[0,i]所表示的字串需要的最小分割次数为dp[i]
  const dp: number[] = Array.from<number>({ length: n }).fill(Infinity)

  //如果[j + 1,i]是一个回文串那么dp[i]就等于min(dp[j] + 1)
  //其中 0 <= j < i，其中当[0,i]是一个回文串的时候他的分割次数也就是dp[i]为0
  for (let i = 0; i < n; ++i) {
    if (g[0][i]) {
      dp[i] = 0
    } else {
      for (let j = 0; j < i; ++j) {
        if (g[j + 1][i]) {
          dp[i] = Math.min(dp[i], dp[j] + 1)
        }
      }
    }
  }

  return dp[n - 1]
}
