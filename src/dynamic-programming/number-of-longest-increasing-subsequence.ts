function findNumberOfLIS(nums: number[]): number {
  if (!nums.length) return 0

  //dp[i]表示以nums[i]结尾能构成的最长递增子序列的长度为dp[i]
  const dp: number[] = []
  //count[i]表示以nums[i]结尾最长递增子序列的个数为count[i]
  const count: number[] = []

  //假设nums中最长递增子序列的长度为maxLen，那么结果就为count[x]的和其中x满足dp[x] = maxLen

  count[0] = dp[0] = 1
  let maxLen = 1
  let ans = 1
  for (let i = 1; i < nums.length; ++i) {
    dp[i] = count[i] = 1
    for (let j = 0; j < i; ++j) {
      if (nums[j] < nums[i]) {
        if (dp[j] + 1 === dp[i]) {
          count[i] += count[j]
        }
        //找到更长的公共子序列将之前的值覆盖了
        else if (dp[j] + 1 > dp[i]) {
          count[i] = count[j]
          dp[i] = dp[j] + 1
        }
      }
    }

    if (dp[i] > maxLen) {
      maxLen = dp[i]
      ans = count[i]
    } else if (dp[i] === maxLen) {
      ans += count[i]
    }
  }

  return ans
}
