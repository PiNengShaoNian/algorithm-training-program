export function containsNearbyDuplicate(nums: number[], k: number): boolean {
  const window = new Set<number>()
  const n = nums.length
  for (let i = 0; i < n; ++i) {
    if (window.has(nums[i])) return true
    window.add(nums[i])

    if (window.size === k + 1) {
      window.delete(nums[i - k])
    }
  }

  return false
}
