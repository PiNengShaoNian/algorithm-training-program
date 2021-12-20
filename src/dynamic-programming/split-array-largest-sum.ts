export function splitArray(nums: number[], m: number): number {
  const n = nums.length
  //dp[i][j]表示将前i个元素分为j组后这些子数组各自和的最大值能达到的最小值
  //其中j <= Math.min(m,i)并且i,j都从1开始
  const dp: number[][] = Array.from({ length: n + 1 }, () =>
    Array.from<number>({ length: m + 1 }).fill(Infinity)
  )

  dp[0][0] = 0

  const presum: number[] = []
  presum[0] = 0
  for (let i = 0; i < n; ++i) {
    presum[i + 1] = nums[i] + presum[i]
  }

  for (let i = 1; i <= n; ++i) {
    for (let j = 1; j <= i && j <= m; ++j) {
      for (let k = 0; k < i; ++k) {
        //前1至k个元素分为j-1组，k到i则分为一组
        //dp[i][j]的答案就可以用Math.max(dp[k][j - 1], presum[i] - presum[k])来
        //更新
        dp[i][j] = Math.min(
          dp[i][j],
          Math.max(dp[k][j - 1], presum[i] - presum[k])
        )
      }
    }
  }

  return dp[n][m]
}
