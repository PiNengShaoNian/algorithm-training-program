export function subarraysDivByK(nums: number[], k: number): number {
  const remainderToCount = new Map<number, number>()
  const n = nums.length
  let ans = 0
  let presum = 0
  let remainder = 0
  remainderToCount.set(0, 1)

  for (let i = 0; i < n; ++i) {
    presum = presum + nums[i]
    remainder = ((presum % k) + k) % k
    ans += remainderToCount.get(remainder) ?? 0

    remainderToCount.set(remainder, (remainderToCount.get(remainder) ?? 0) + 1)
  }

  return ans
}
