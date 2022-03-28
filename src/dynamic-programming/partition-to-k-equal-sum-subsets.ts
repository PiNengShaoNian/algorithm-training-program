function canPartitionKSubsets(nums: number[], k: number): boolean {
  const n = nums.length
  let sum = 0
  for (let i = 0; i < n; ++i) {
    sum += nums[i]
  }

  if (sum % k !== 0) return false

  nums.sort((a, b) => b - a)
  const groups: number[] = Array.from<number>({ length: k }).fill(0)
  const target = sum / k

  const Impl = (idx: number): boolean => {
    if (idx >= n) {
      for (let i = 0; i < k; ++i) {
        if (groups[i] !== target) return false
      }
      return true
    }

    for (let i = 0; i < k; ++i) {
      const num = nums[idx]
      if (num + groups[i] <= target) {
        groups[i] += num
        if (Impl(idx + 1)) return true
        groups[i] -= num
      }

      //num放进groups[i]会失败，那么他也放不进后面的group直接返回
      if (groups[i] === 0) break
    }

    return false
  }

  return Impl(0)
}
