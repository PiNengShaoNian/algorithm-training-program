export function numberOfArithmeticSlices(nums: number[]): number {
  if (nums.length < 3) return 0
  let t = 0
  let ans = 0

  for (let i = 2; i < nums.length; ++i) {
    if (nums[i] - nums[i - 1] === nums[i - 1] - nums[i - 2]) {
      ans += ++t
    } else {
      t = 0
    }
  }

  return ans
}
