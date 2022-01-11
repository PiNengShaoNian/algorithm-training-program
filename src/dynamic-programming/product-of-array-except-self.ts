export function productExceptSelf(nums: number[]): number[] {
  const n = nums.length
  let preProduct: number[] = [1]
  let preProductReverse = Array.from<number>({ length: n + 1 })
  preProductReverse[n] = 1

  for (let i = 0; i < n; ++i) {
    preProduct[i + 1] = preProduct[i] * nums[i]
    preProductReverse[n - i - 1] = preProductReverse[n - i] * nums[n - i - 1]
  }

  const output = []

  for (let i = 0; i < n; ++i) {
    output[i] = preProductReverse[i + 1] * preProduct[i]
  }

  return output
}

//O(1)空间复杂度解法
export function productExceptSelf1(nums: number[]): number[] {
  const ans: number[] = []
  const n = nums.length
  ans[0] = 1

  for (let i = 1; i < n; ++i) {
    ans[i] = ans[i - 1] * nums[i - 1]
  }

  let R = 1

  for (let i = n - 1; i >= 0; --i) {
    ans[i] = ans[i] * R
    R *= nums[i]
  }

  return ans
}
