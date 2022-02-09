function subarraysWithKDistinct(nums: number[], k: number): number {
  //和binary-subarrays-with-sum一模一样的思路，固定一个r
  //如果存在一个l1他是满足条件的最小坐标值，且存在一个l2他是满足条件
  //的最大坐标值加一，则有l1 <= l < l2,其中[l,r]这些区间都是满足
  //条件的子数组，对于r他会为答案贡献l2 - l1个满足条件的子数组
  const n = nums.length
  let l1 = 0
  let l2 = 0
  let r = 0
  const window1 = new Map<number, number>()
  const window2 = new Map<number, number>()
  let ans = 0
  const minusOne = (map: Map<number, number>, key: number): void => {
    const newCount = map.get(key)! - 1

    if (newCount === 0) {
      map.delete(key)
    } else {
      map.set(key, newCount)
    }
  }
  for (; r < n; ++r) {
    window1.set(nums[r], (window1.get(nums[r]) ?? 0) + 1)
    window2.set(nums[r], (window2.get(nums[r]) ?? 0) + 1)

    while (l2 <= r && window2.size >= k) {
      minusOne(window2, nums[l2])
      ++l2
    }

    while (l1 <= r && window1.size > k) {
      minusOne(window1, nums[l1])
      ++l1
    }

    ans += l2 - l1
  }

  return ans
}
