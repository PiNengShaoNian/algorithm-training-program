export function largestDivisibleSubset(nums: number[]): number[] {
  nums.sort((a, b) => a - b)
  //dp[i]表示以nums[i]为结尾的升序数组中能构成的最大整除子集长度
  //为dp[i]
  const dp: number[] = []
  dp[0] = 1
  let maxSize = 1
  let maxVal = nums[0]
  const n = nums.length
  for (let i = 1; i < n; ++i) {
    dp[i] = 1
    for (let j = 0; j < i; ++j) {
      if (nums[i] % nums[j] === 0) {
        dp[i] = Math.max(dp[i], dp[j] + 1)
      }
    }

    if (dp[i] > maxSize) {
      maxSize = dp[i]
      maxVal = nums[i]
    }
  }

  if (maxSize === 1) {
    return [nums[0]]
  }
  const ans: number[] = []
  for (let i = n - 1; i >= 0 && maxSize > 0; --i) {
    if (maxSize === dp[i] && maxVal % nums[i] === 0) {
      ans.push(nums[i])
      --maxSize
      maxVal = nums[i]
    }
  }

  return ans
}
