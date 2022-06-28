export function findIntegers(n: number): number {
  const dp: number[] = []
  //dp[i]表示长度未i且没有连续1的数字数量
  dp[0] = 1 // {ε} 长度为0的数字只有空一个
  dp[1] = 2 // {0,1}
  dp[2] = 3 // {00,01,10} 11因为出现了连续1所以不满足

  //递归公式的状态转移可以看 https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones/comments/109930
  // S -> 10S | 0S | 0 | 1 | ε
  //当i >= 2时(满足该条件的生产式只有，S -> 10S | 0S)，也就是dp[i]所表示的数字可以由dp[i-1]左侧加零
  //或者由dp[i-2]左侧加10获得，即递推式dp[n] = dp[n - 2] + dp[n - 1]
  for (let i = 2; i <= 32; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2]
  }

  //当前遍历到bit的前一个bit值
  let prev = 0

  let ans = 0
  for (let i = 30; i >= 0; --i) {
    if ((1 << i) & n) {
      //该bit为1,则我们可以把这个位替换为0，那么这种情况下增加的满足条件的数字就有
      // xxxxxxxxxxxxxxxxxxxxx                    bit                         xxxxxxxxxxxxxxxxxx
      //    prefix(没有连续1的前缀)        当前遍历为1的bit(currentBit)           suffix(剩下的后缀)
      //再把bit替换为0后，此时增加答案的数量就是dp[suffix.length],我们不用担心产生的数字会大于n,因为bit替换为0后
      //prefix-0-[xxxx]一定小于prefix-1-suffix，不管xxxxx的序列是啥
      ans += dp[i]

      //已经出现了连续的1后续不会出现没有连续1的prefix了，直接返回答案
      if (prev) {
        return ans
      }

      //在下一次循环之前设置prevBit
      prev = 1
    } else {
      //重置prevBit
      prev = 0
    }
  }

  return ans + 1
}
