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

export function countSubstrings1(s: string): number {
  const n = s.length
  let ans = 0
  for (let i = 0; i < 2 * n - 1; ++i) {
    let l = i >> 1
    let r = l + (i % 2)

    while (l >= 0 && r < n && s[l] === s[r]) {
      --l
      ++r
      ++ans
    }
  }

  return ans
}
