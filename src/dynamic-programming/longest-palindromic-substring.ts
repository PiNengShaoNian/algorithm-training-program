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

export function longestPalindrome2(s: string): string {
  const n = s.length
  // 在实现的时候，我们需要处理一个问题，即如何有序地枚举所有可能的回文中心，
  // 我们需要考虑回文长度是奇数和回文长度是偶数的两种情况。 如果回文长度是
  // 奇数，那么回文中心是一个字符；如果回文长度是偶数，那么中心是两个字符。
  // 当然你可以做两次循环来分别枚举奇数长度和偶数长度的回文， 但是我们也
  // 可以用一个循环搞定。我们不妨写一组出来观察观察，
  // 假设 n = 4，我们可以把可能的回文中心列出来：
  // 标号i       回文中心左起位置li         回文中心右起始位置ri
  //  0                 0                           0
  //  1                 0                           1
  //  2                 1                           1
  //  3                 1                           2
  //  4                 2                           2
  //  5                 2                           3
  //  6                 3                           3
  // 由此我们可以看出长度为 n 的字符串会生成 2n-1 组回文中心
  // 其中li = i / 2, ri = li + (i mod 2)
  // 这样我们只要从 00 到 2n - 22n−2 遍历 ii，
  // 就可以得到所有可能的回文中心,这样就把奇数长度和偶数长度两种情况统一起来了
  let lb = 0
  let rb = 0
  let max = 1
  for (let i = 0; i < 2 * n - 1; ++i) {
    let l = i >> 1
    let r = l + (i % 2)

    while (l >= 0 && r < n && s[l] === s[r]) {
      if (r - l + 1 > max) {
        lb = l
        rb = r
        max = r - l + 1
      }

      --l
      ++r
    }
  }

  return s.slice(lb, rb + 1)
}
