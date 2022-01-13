export function numSubarrayProductLessThanK(nums: number[], k: number): number {
  if (k <= 1) return 0
  let l = 0
  let r = 0
  let ans = 0
  const n = nums.length
  let product = 1
  for (; r < n; ++r) {
    product *= nums[r]

    while (product >= k) {
      product /= nums[l]
      ++l
    }

    ans += r - l + 1
  }

  return ans
}

export function numSubarrayProductLessThanK1(
  nums: number[],
  k: number
): number {
  const n = nums.length
  const prefix: number[] = []
  const logk = Math.log(k)
  prefix[0] = 0

  for (let i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + Math.log(nums[i])
  }

  let ans = 0

  for (let i = 0; i < n; ++i) {
    let lo = i + 1
    let hi = n
    let x = i
    while (lo <= hi) {
      const mid = lo + ((hi - lo) >> 1)

      if (prefix[mid] < logk + prefix[i] - 1e-9) {
        lo = mid + 1
        x = mid
      } else {
        hi = mid - 1
      }
    }

    ans += x - i
  }

  return ans
}
