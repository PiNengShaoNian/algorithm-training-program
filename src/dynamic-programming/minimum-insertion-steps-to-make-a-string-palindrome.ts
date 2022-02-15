export function minInsertions(s: string): number {
  //最简单的思路，先求出一个字符串中的最长回文子序列p, len(s) - len(p)
  //就是那些让s不能成为回文串的字符个数,现在要让s成为回文字符串也很简单
  //在每个这种字符的对称位置添加一个和他相等的字符就能使他成为回文串
  //比如字符串s = "leet",他的最长回文子序列p = "ee"，导致s不能成为回文串的
  //字符就有第一个"l"和最后一个字符"t",接下来我们只需要插入两个字符，就能使
  //s成为回文串
  //第一步在最后的位置插入一个"l",  "leet"  --> "leetl"
  //第二步在第二个的位置插入一个"t" "leetl" --> "lteetl"
  //所以我们要的结果就为 len(s) - len(p)，这题转换为求最长回文子序列了

  let max = 1
  const n = s.length
  const dp: number[][] = []
  for (let i = 0; i < n; ++i) {
    dp[i] = Array.from<number>({ length: n }).fill(0)
  }

  for (let i = n - 1; i >= 0; --i) {
    dp[i][i] = 1
    for (let j = i + 1; j < n; ++j) {
      const equal = s[i] === s[j]
      dp[i][j] = equal
        ? dp[i + 1][j - 1] + 2
        : Math.max(dp[i + 1][j], dp[i][j - 1])

      max = Math.max(max, dp[i][j])
    }
  }

  return n - max
}

export function minInsertions1(s: string): number {
  //和上面的解法通过最长回文子序列的变相思路解题不同，这题直接通过dp的状态
  //和定义和状态之间的转移直接推导出结果

  //dp[i][j]表示s[i:j]区间的字符串要使其变为回文串，最少需要插入字符的个数
  const dp: number[][] = []
  const n = s.length
  for (let i = 0; i < n; ++i) {
    dp[i] = Array.from<number>({ length: n }).fill(0)
  }

  for (let i = n - 1; i >= 0; --i) {
    for (let j = i + 1; j < n; ++j) {
      //要使s[i:j]成为回文串有以下两种选择
      //(1) 缩小左区间在字符串s[i+1:j]的前面插入一个s[j]字符
      //(2) 缩小右区间在字符串s[i,j-1]的后面插入一个s[i]字符
      dp[i][j] = Math.min(dp[i + 1][j], dp[i][j - 1]) + 1

      //特殊情况，s[i]和s[j]相等这种情况下我们也可以选择不缩小区间插入字符
      //我们可以选择直接在字符串s[i+1:j-1]两边包上s[i]字符就行，也能使s[i][j]
      //变成回文串
      if (s[i] === s[j]) {
        dp[i][j] = Math.min(dp[i + 1][j - 1], dp[i][j])
      }
    }
  }

  return dp[0][n - 1]
}
