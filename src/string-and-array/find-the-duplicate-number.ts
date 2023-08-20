export function findDuplicate(nums: number[]): number {
  // 设cnt[i]为nums中小于等于数字i的数量
  // 比如nums为[1,3,4,2,2]时cnt数组为
  // 数字i:  1  2   3  4
  // cnt[i]  1  3   4  5
  // 容易观察出出现重复的数字是第一个(cnt[i] > i)的数字
  // 并且cnt数字是单调递增的所以我们自然想到可以使用二分查找解题
  const n = nums.length
  let l = 1 // 数组中可能出现的最小数字
  let r = n - 1 //数组中可能出现的最大数字
  let ans = -1
  while (l <= r) {
    const mid = l + ((r - l) >> 1) // 枚举数字
    let cnt = 0 // 计算出nums中有几个数字小于等于mid

    for (let i = 0; i < n; i++) {
      cnt += nums[i] <= mid ? 1 : 0
    }

    // cnt大于mid满足条件(也就是cnt[mid] > mid)，但是可能还有更靠前满足条件的数字
    if (cnt > mid) {
      ans = mid
      r = mid - 1
    } else {
      l = mid + 1
    }
  }

  return ans
}

// 快慢指针解法
export function findDuplicate1(nums: number[]): number {
  let slow = 0
  let fast = 0

  while (true) {
    slow = nums[slow]
    fast = nums[nums[fast]]

    if (slow === fast) {
      break
    }
  }

  slow = 0
  while (slow != fast) {
    slow = nums[slow]
    fast = nums[fast]

    if (slow === fast) {
      return slow
    }
  }

  return slow
}
