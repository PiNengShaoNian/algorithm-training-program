export function isScramble(s1: string, s2: string): boolean {
  const check = (i: number, j: number, len: number): boolean => {
    const count: number[] = Array.from<number>({ length: 26 }).fill(0)

    for (let s = 0; s < len; ++s) {
      ++count[s1.charCodeAt(s + i) - 97]
      --count[s2.charCodeAt(s + j) - 97]
    }

    for (let i = 0; i < count.length; ++i) {
      if (count[i] !== 0) return false
    }

    return true
  }

  const n = s1.length
  const memo: boolean[][][] = []
  for (let i = 0; i < n; ++i) {
    memo[i] = []
    for (let j = 0; j < n; ++j) {
      memo[i][j] = []
    }
  }

  const Impl = (i: number, j: number, len: number): boolean => {
    if (typeof memo[i][j][len] === 'boolean') return memo[i][j][len]

    if (s1.substr(i, len) === s2.substr(j, len)) {
      memo[i][j][len] = true
      return true
    }
    if (!check(i, j, len)) {
      memo[i][j][len]
      return false
    }

    for (let k = 1; k < len; ++k) {
      //选择不反转
      //s1: xxx xxxxxx
      //s2: xxx xxxxxx
      //k = 3
      if (Impl(i, j, k) && Impl(i + k, j + k, len - k)) {
        memo[i][j][len] = true
        return true
      }

      //选择反转
      //s1: xxx xxxxxx
      //s2: xxxxxx xxx
      //k = 3
      if (Impl(i, j + len - k, k) && Impl(i + k, j, len - k)) {
        memo[i][j][k] = true
        return true
      }
    }

    memo[i][j][len] = false
    return false
  }

  if (s1.length !== s2.length) return false

  return Impl(0, 0, s1.length)
}

//根据上面的思路可以写出自底向上的递推方法
export function isScramble1(s1: string, s2: string): boolean {
  const n = s1.length
  const dp: boolean[][][] = []
  for (let i = 0; i < n; ++i) {
    dp[i] = []
    for (let j = 0; j < n; ++j) {
      dp[i][j] = []
      dp[i][j][1] = s1[i] === s2[j]
    }
  }

  for (let len = 2; len <= n; ++len) {
    for (let i = 0; i <= n - len; ++i) {
      for (let j = 0; j <= n - len; ++j) {
        for (let k = 1; k < len; ++k) {
          const a = dp[i][j][k] && dp[i + k][j + k][len - k]
          const b = dp[i][j + len - k][k] && dp[i + k][j][len - k]

          if (a || b) {
            dp[i][j][len] = true
          }
        }
      }
    }
  }

  return !!dp[0][0][s1.length]
}
