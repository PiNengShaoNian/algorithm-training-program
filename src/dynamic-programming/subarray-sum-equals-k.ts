export function subarraySum(nums: number[], k: number): number {
  let presum = 0
  const presumToCount = new Map<number, number>()
  const n = nums.length
  presumToCount.set(0, 1)
  let ans = 0
  for (let i = 0; i < n; ++i) {
    presum += nums[i]
    ans += presumToCount.get(presum - k) ?? 0

    presumToCount.set(presum, (presumToCount.get(presum) ?? 0) + 1)
  }

  return ans
}
