export function combinationSum4(nums: number[], target: number): number {
  //dp[i]表示一个大小为i的数有多少种组成方法
  const dp: number[] = Array.from<number>({ length: target + 1 }).fill(0)
  dp[0] = 1
  for (let i = 1; i <= target; ++i) {
    for (const num of nums) {
      if (i >= num) {
        dp[i] += dp[i - num]
      }
    }
  }

  return dp[target]
}
