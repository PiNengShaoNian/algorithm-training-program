function countSubstrings(s: string): number {
  const g: boolean[][] = []
  const n = s.length
  for (let i = 0; i < n; ++i) {
    g[i] = []

    for (let j = 0; j < n; ++j) {
      g[i][j] = true
    }
  }

  //还是回文串题的一贯思路先预处理字符串
  //找出所有回文区间，然后在枚举答案
  for (let i = n - 1; i >= 0; --i) {
    for (let j = i + 1; j < n; ++j) {
      g[i][j] = s[i] === s[j] && g[i + 1][j - 1]
    }
  }

  let ans = 0
  for (let i = 0; i < n; ++i) {
    for (let j = i; j < n; ++j) {
      if (g[i][j]) {
        ++ans
      }
    }
  }

  return ans
}
