const core = (nums: number[]): number => {
  const n = Math.floor((nums.length + 1) / 3)
  //dp[i][j]代表在前i个数中选取了j个不相邻的数能构成的最大和
  const dp: number[][] = []

  for (let i = 0; i <= nums.length; ++i) {
    dp[i] = []
    dp[i][0] = 0
  }

  for (let i = 0; i <= n; ++i) {
    dp[0][i] = 0
  }

  for (let i = 1; i <= nums.length; ++i) {
    for (let j = 1; j <= n; ++j) {
      dp[i][j] = Math.max(
        //选了第i个数,之前的数字就只能在[0,i- 2]区间内选择
        (i - 2 >= 0 ? dp[i - 2][j - 1] : 0) + nums[i - 1],
        //不选第i个数
        dp[i - 1][j]
      )
    }
  }

  return dp[nums.length][n]
}

//菜的抠脚压根看不懂证明，只知道是问题等价于求一个从3n长的循环数组中
//挑选n个互不相邻的数能构成的最大和
export function maxSizeSlices(slices: number[]): number {
  return Math.max(
    core(slices.slice(1)),
    core(slices.slice(0, slices.length - 1))
  )
}
