//动态规划解法时间复杂度O(N ^ 2)
export function longestPalindrome(s: string): string {
  const n = s.length
  const dp: boolean[][] = []

  for (let i = 0; i < n; ++i) {
    dp[i] = []
    for (let j = 0; j < n; ++j) {
      dp[i][j] = true
    }
  }

  for (let i = n - 1; i >= 0; --i) {
    for (let j = i + 1; j < n; ++j) {
      dp[i][j] = s[i] === s[j] && dp[i + 1][j - 1]
    }
  }

  let max = 1
  let ans = s[0]
  for (let i = 0; i < n; ++i) {
    for (let j = i; j < n; ++j) {
      if (dp[i][j] && j - i + 1 > max) {
        max = j - i + 1
        ans = s.substr(i, max)
      }
    }
  }

  return ans
}

//枚举回文串中点然后向两边拓展，动态构建回文串
//时间复杂度O(N ^ 2)但是常数很小比上面的解法快十几倍
export function longestPalindrome1(s: string): string {
  let ansLen = 1
  let ansStart = 0
  const n = s.length

  //回文串的中点是一个字符
  for (let i = 1; i < n; ++i) {
    let l = i - 1
    let r = i + 1

    while (l >= 0 && r < n && s[l] === s[r]) {
      --l
      ++r
    }

    if (r - l - 1 > ansLen) {
      ansLen = r - l - 1
      ansStart = l + 1
    }
  }

  //回文串的中点是两个字符
  for (let i = 0; i < n; ++i) {
    let l = i
    let r = i + 1

    while (l >= 0 && r < n && s[l] === s[r]) {
      --l
      ++r
    }

    if (r - l - 1 > ansLen) {
      ansLen = r - l - 1
      ansStart = l + 1
    }
  }

  return s.substr(ansStart, ansLen)
}
