//暴力解法，枚举以每个位置为起点的最长括号串
export function longestValidParentheses(s: string): number {
  const validParenthesesFromIndex = (k: number) => {
    const stack: string[] = []
    let max = 0
    let ans = 0
    for (let i = k; i < s.length; ++i) {
      if (s[i] === ')') {
        if (!stack.length || stack[stack.length - 1] !== '(') {
          return ans
        }

        stack.pop()
        max += 2
        if (!stack.length) {
          ans = Math.max(ans, max)
        }
      } else {
        stack.push(s[i])
      }
    }

    return ans
  }
  let ans = 0
  for (let i = 0; i < s.length; ++i) {
    ans = Math.max(ans, validParenthesesFromIndex(i))
  }

  return ans
}

//动态规划解法
export function longestValidParentheses1(s: string): number {
  const n = s.length
  //dp[i]代表以s[i]为结尾最长的有效括号串的长度为dp[i]
  const dp: number[] = Array.from<number>({ length: n }).fill(0)

  let ans = 0
  for (let i = 1; i < n; ++i) {
    if (s[i] === ')') {
      //如果前一个字符是(则dp[i]可以等于dp[i - 2] + 2
      //需要特殊处理i - 2的情况
      if (s[i - 1] === '(') {
        dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2
      } else if (s[i - 1] === ')') {
        //如果前一个字符也是)，并且以dp[i - 1]代表的有效括号串的前一个
        //字符也是(那么dp[i]就等于dp[i - 1] + 2，并且还得加上之前的有效串长度
        // dp[i-dp[i-1]-2]   i - dp[i - 1] - 1                   i
        //     ^             ^                                   ^
        //     |             |                                   |
        // 前面的有效串长度   (    ......dp[i - 1]所代表的串       )
        if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] === '(') {
          dp[i] =
            dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2
        }
      }
    }

    ans = Math.max(ans, dp[i])
  }

  return ans
}
