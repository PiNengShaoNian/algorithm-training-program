export function checkSubarraySum(nums: number[], k: number): boolean {
  let presum = 0
  const presumToIndex = new Map<number, number>()
  const n = nums.length
  presumToIndex.set(0, -1)

  for (let i = 0; i < n; ++i) {
    presum = (presum + nums[i]) % k
    if (presumToIndex.has(presum)) {
      //如果presumR和presumL模k有相同的余数则presumR - presumL是k的倍数
      if (i - presumToIndex.get(presum)! >= 2) return true
    } else {
      presumToIndex.set(presum, i)
    }
  }

  return false
}
