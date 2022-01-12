export function findMiddleIndex(nums: number[]): number {
  const n = nums.length
  const presum: number[] = [0]

  for (let i = 0; i < n; ++i) {
    presum[i + 1] = nums[i] + presum[i]
  }

  let presumReverse = 0
  let ans = -1
  for (let i = n - 1; i >= 0; --i) {
    if (presum[i] === presumReverse) {
      ans = i
    }

    presumReverse = presumReverse + nums[i]
  }

  return ans
}
