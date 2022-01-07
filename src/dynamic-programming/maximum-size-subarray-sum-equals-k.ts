function maxSubArrayLen(nums: number[], k: number): number {
  let presum: number[] = [0]
  const presumToIndex = new Map<number, number>()
  presumToIndex.set(0, 0)
  const n = nums.length
  for (let i = 0; i < n; ++i) {
    presum[i + 1] = presum[i] + nums[i]
    if (!presumToIndex.has(presum[i + 1])) {
      presumToIndex.set(presum[i + 1], i + 1)
    }
  }

  let ans = 0
  for (let i = 1; i <= n; ++i) {
    if (presumToIndex.has(presum[i] - k)) {
      //presum[i] - presum[l] = k
      //presum[l] = presum[i] - k
      ans = Math.max(ans, i - presumToIndex.get(presum[i] - k)!)
    }
  }

  return ans
}
