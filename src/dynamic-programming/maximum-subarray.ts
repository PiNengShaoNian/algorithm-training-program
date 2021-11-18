export function maxSubArray(nums: number[]): number {
  //dp[i]表示以nums[i]结尾最大的子序和dp[i]
  const dp: number[] = []

  dp[0] = nums[0]
  let ans = nums[0]

  for (let i = 1; i < nums.length; ++i) {
    if (dp[i - 1] < 0) {
      dp[i] = nums[i]
    } else {
      dp[i] = nums[i] + dp[i - 1]
    }

    ans = Math.max(ans, dp[i])
  }

  return ans
}

export function maxSubArray1(nums: number[]): number {
  //不难看出如果我们要求出最大子序和，那么只需要求出前缀和presum
  //然后在求出最大的presum[i] - presum[j]即可,其中j < i,  0<=i,j <= n
  const presum: number[] = []
  presum[0] = 0
  for (let i = 1; i <= nums.length; ++i) {
    presum[i] = presum[i - 1] + nums[i - 1]
  }

  let minPresum = 0
  let ans = nums[0]
  for (let i = 1; i < presum.length; ++i) {
    ans = Math.max(ans, presum[i] - minPresum)
    minPresum = Math.min(presum[i], minPresum)
  }

  return ans
}
