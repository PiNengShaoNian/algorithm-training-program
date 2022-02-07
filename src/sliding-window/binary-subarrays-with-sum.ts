export function numSubarraysWithSum(nums: number[], goal: number): number {
  const n = nums.length
  const presumToCount = new Map<number, number>()
  let presum = 0

  presumToCount.set(0, 1)
  let ans = 0
  for (let i = 0; i < n; ++i) {
    presum += nums[i]
    ans += presumToCount.get(presum - goal) ?? 0

    presumToCount.set(presum, (presumToCount.get(presum) ?? 0) + 1)
  }

  return ans
}

export function numSubarraysWithSum1(nums: number[], goal: number): number {
  let l1 = 0
  let l2 = 0
  let s1 = 0
  let s2 = 0
  let r = 0
  const n = nums.length
  let ans = 0

  for (; r < n; ++r) {
    s1 += nums[r]
    s2 += nums[r]

    //l1 <= l < l2,其中[l,r]的区间和都满足目标，这题数字只有零和一而且没有
    //负数才能这样做
    while (l2 <= r && s2 >= goal) s2 -= nums[l2++]

    while (l1 <= r && s1 > goal) s1 -= nums[l1++]

    ans += l2 - l1
  }

  return ans
}
