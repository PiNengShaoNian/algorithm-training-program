export function lengthOfLIS(nums: number[]): number {
  /**
      dp[i]表示以nums[i]结尾能构成的最长递增子序列为i
     */
  const dp: number[] = []

  dp[0] = 1
  let ans = 1

  for (let i = 1; i < nums.length; ++i) {
    dp[i] = 1
    for (let j = 0; j < i; ++j) {
      if (nums[j] < nums[i]) {
        dp[i] = Math.max(dp[i], dp[j] + 1)
      }
    }

    ans = Math.max(dp[i], ans)
  }

  return ans
}

export function lengthOfLIS1(nums: number[]): number {
  //通过二分查找插入位置动态构建出来的最长递增子序列
  //tails[i]表示长度为i的最长递增子序列，该序列最后的一个数字的最小值为tails[i]
  const tails: number[] = []
  let len = 1
  tails[1] = nums[0]

  for (let i = 1; i < nums.length; ++i) {
    if (nums[i] > tails[len]) {
      tails[++len] = nums[i]
    } else {
      //左边从1开始tails[0]为未定义行为
      let l = 1
      let r = len
      let pos = 0

      while (l <= r) {
        const mid = (l + r) >> 1
        if (tails[mid] < nums[i]) {
          pos = mid
          l = mid + 1
        } else {
          r = mid - 1
        }
      }

      tails[pos + 1] = nums[i]
    }
  }

  return len
}
