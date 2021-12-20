function minSubArrayLen(s: number, nums: number[]): number {
  let l = 0
  let r = -1
  let sum = 0
  let res = nums.length + 1

  while (l < nums.length) {
    if (r + 1 < nums.length && sum < s) sum += nums[++r]
    else sum -= nums[l++]

    if (sum >= s) {
      res = Math.min(res, r - l + 1)
    }
  }

  if (res === nums.length + 1) return 0
  else return res
}
