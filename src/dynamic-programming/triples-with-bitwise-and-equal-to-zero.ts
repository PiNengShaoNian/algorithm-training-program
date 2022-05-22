function countTriplets(nums: number[]): number {
  const MAX = 1 << 16
  const cnt = new Int32Array(MAX)
  const n = nums.length

  for (let i = 0; i < n; ++i) {
    for (let j = 0; j < n; ++j) {
      ++cnt[nums[i] & nums[j]]
    }
  }

  let ans = 0
  for (let i = 0; i < n; ++i) {
    const full = MAX - 1 - nums[i]

    //枚举full子状态
    for (let j = full; j > 0; j = (j - 1) & full) {
      ans += cnt[j]
    }

    ans += cnt[0]
  }

  return ans
}
