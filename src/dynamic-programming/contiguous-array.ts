function findMaxLength(nums: number[]): number {
  const n = nums.length

  let presum = 0
  const presumToIndex = new Map<number, number>()
  presumToIndex.set(0, 0)
  let ans = 0
  for (let i = 1; i <= n; ++i) {
    presum = presum + (nums[i - 1] === 0 ? -1 : 1)
    //更新答案
    if (presumToIndex.has(presum)) {
      const prevIndex = presumToIndex.get(presum)
      ans = Math.max(ans, i - prevIndex)
    } else {
      presumToIndex.set(presum, i)
    }
  }

  return ans
}
