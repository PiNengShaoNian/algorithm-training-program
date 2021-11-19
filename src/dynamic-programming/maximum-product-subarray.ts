export function maxProduct(nums: number[]): number {
  //由于负数的存在，可能当前还是最大的乘积，经过一次乘法后就会变成最小的乘积
  //最小的乘积又会变成最大的乘积，所以我们同时保存最大和最小的乘积

  //dpMax[i]代表以nums[i]结尾最大的乘积为dpMax[i]
  const dpMax: number[] = []
  //dpMin[i]代表以nums[i]结尾最小的乘积为dpMax[i]
  const dpMin: number[] = []

  let ans = (dpMax[0] = dpMin[0] = nums[0])

  for (let i = 1; i < nums.length; ++i) {
    dpMax[i] = Math.max(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i], nums[i])
    dpMin[i] = Math.min(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i], nums[i])

    ans = Math.max(dpMax[i], ans)
  }

  return ans
}
