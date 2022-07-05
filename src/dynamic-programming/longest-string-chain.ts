//LIS模板题
export function longestStrChain(words: string[]): number {
  //词链的长度一定是按长度升序排列的，我们可以在排序后的单词中寻找最长
  //“递增”子序列长度即可，这里两个单词a和b递增的条件是：
  //1. b的长度比a长1
  //2. 且a中字母出现的顺序和在b中以同样的顺序出现
  words.sort((a, b) => a.length - b.length)

  const n = words.length
  //dp[i]标识已第i个单词为结尾能形成的最长词链长度
  const dp: number[] = []
  dp[0] = 1
  let ans = 1

  //LIS模板
  for (let i = 1; i < n; ++i) {
    dp[i] = 1
    loop: for (let j = i - 1; j >= 0; --j) {
      const diff = words[i].length - words[j].length

      switch (diff) {
        //判断是否满足递增的条件1
        case 1:
          let indexI = 0
          let indexJ = 0
          const lenI = words[i].length
          let skip = false
          //判断是否满足递增的条件2
          while (indexI < lenI) {
            if (words[i][indexI] === words[j][indexJ]) {
              ++indexI
              ++indexJ
            } else if (!skip) {
              skip = true
              ++indexI
            } else {
              break
            }
          }

          if (indexI === lenI) {
            dp[i] = Math.max(dp[i], dp[j] + 1)
          }
          break
        //长度相等，继续向前枚举j
        case 0:
          break
        //长度差距大于1，再往前长度差距只会更大永远不会满足递增条件的条件1，在这里提前退出
        default:
          break loop
      }
    }

    ans = Math.max(ans, dp[i])
  }

  return ans
}
