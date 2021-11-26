export function longestArithSeqLength(nums: number[]): number {
  //dp.get(i + '-' + j)代表以nums[i]为结尾，以j为等差的子序列长度为dp.get(i + '-' + j)
  const dp = new Map<string, number>()
  const n = nums.length
  let ans = 0
  for (let i = 0; i < n; ++i) {
    for (let j = 0; j < i; ++j) {
      const step = nums[i] - nums[j]
      const key = i + '-' + step
      dp.set(key, (dp.get(j + '-' + step) ?? 1) + 1)
      ans = Math.max(ans, dp.get(key)!)
    }
  }

  return ans
}
