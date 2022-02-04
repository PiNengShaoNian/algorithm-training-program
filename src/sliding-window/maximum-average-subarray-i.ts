export function findMaxAverage(nums: number[], k: number): number {
  let sum = -Infinity
  const n = nums.length

  let l = 0
  let r = -1

  let window = 0

  while (l < n) {
    while (r + 1 < n && r - l + 1 < k) {
      window += nums[++r]
    }

    if (window > sum && r - l + 1 === k) {
      sum = window
    }

    window -= nums[l]
    ++l
  }

  return sum / k
}
