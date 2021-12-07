export function minSwap(nums1: number[], nums2: number[]): number {
  //在dp[i][j]中j为0或1代表交换或不交换i元素
  //dp[i][j]代表在nums[0-i]区间内的子数组最少交换dp[i][j]次才能使两个数组有序
  const dp: number[][] = []
  const n = nums1.length
  for (let i = 0; i < n; ++i) {
    dp[i] = []
  }
  //交换第一个元素
  dp[0][1] = 1
  //不交换
  dp[0][0] = 1

  for (let i = 1; i < n; ++i) {
    if (nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i]) {
      if (nums1[i - 1] < nums2[i] && nums1[i - 1] < nums2[i]) {
        //i元素和i-1元素都可以选择交换或者不交换
        // [1, 3, 5]
        //        ∧
        //        |
        //        ∨
        // [2, 4, 6]
        dp[i][0] = Math.min(dp[i - 1][0], dp[i - 1][1])
        dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][1]) + 1
      } else {
        //i和i-1只能选择同时交换或者不交换
        dp[i][0] = dp[i - 1][0]
        dp[i][1] = dp[i - 1][1] + 1
      }
    } else {
      dp[i][0] = dp[i - 1][1] // 不交换，则上个位置必须交换
      dp[i][1] = dp[i - 1][0] + 1 // 交换，则上个位置不能交换
    }
  }

  return Math.min(dp[n - 1][0], dp[n - 1][1])
}
