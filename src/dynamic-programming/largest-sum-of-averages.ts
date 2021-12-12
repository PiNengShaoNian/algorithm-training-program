export function largestSumOfAverages(nums: number[], k: number): number {
  const n = nums.length
  //dp[i][k]表示将前i的个元素分为k组能得到的最大分数为dp[i][k]
  const dp: number[][] = []

  for (let i = 0; i <= n; ++i) {
    dp[i] = Array.from<number>({ length: k + 1 }).fill(0)
  }
  const presum: number[] = []
  presum[0] = 0

  for (let i = 0; i < n; ++i) {
    presum[i + 1] = presum[i] + nums[i]
  }

  for (let i = 1; i <= n; ++i) {
    //将前i个元素分为1组的值为presum[i] / i
    dp[i][1] = presum[i] / i
    for (let K = 2; K <= k && K <= i; ++K) {
      for (let j = 1; j < i; ++j) {
        dp[i][K] = Math.max(
          dp[i][K],
          //在1 ... j ... i区间中将[1...j]个元素分为k - 1组
          //将j + 1到i个元素分为一组
          dp[j][K - 1] + (presum[i] - presum[j]) / (i - j)
        )
      }
    }
  }

  return dp[n][k]
}
