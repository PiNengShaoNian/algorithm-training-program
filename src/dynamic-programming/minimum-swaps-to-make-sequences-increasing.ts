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
  dp[0][0] = 0

  for (let i = 1; i < n; ++i) {
    if (nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i]) {
      if (nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i]) {
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
        // [1, 3, 4]
        //        ∧
        //        |
        //        ∨
        // [2, 5, 6]
        dp[i][0] = dp[i - 1][0] //选择交换
        dp[i][1] = dp[i - 1][1] + 1 //选择不交换
      }
    } else {
      //能进到这里说明nums[i - 1]会大于nums[i]
      // [1, 6, 4]
      //        ∧
      //        |
      //        ∨
      // [1, 3, 7]
      //如果i不交换则i - 1必须交换，如果i交换则i-1一定不能交换
      //上面的假设都是建立在由解的情况下的(题目保证输入有效)，比如下面的序列
      //虽然满足nums[i - 1]大于nums[j],但是不管怎么交换都是不会得到正确答案的
      // [1, 8, 7]
      //        ∧
      //        |
      //        ∨
      // [2, 5, 6]

      dp[i][0] = dp[i - 1][1] // 不交换，则上个位置必须交换
      dp[i][1] = dp[i - 1][0] + 1 // 交换，则上个位置不能交换
    }
  }

  return Math.min(dp[n - 1][0], dp[n - 1][1])
}
