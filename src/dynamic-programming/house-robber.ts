//比较好想到的
export function rob(nums: number[]): number {
  //dp[1][i]代表抢劫了nums[i]中的钱能获得的最大收益
  //dp[0][i]代表不抢劫nums[i]中的钱能获得的最大收益
  const dp: number[][] = [[], []]

  dp[1][0] = nums[0]
  dp[0][0] = 0
  let ans = nums[0]
  for (let i = 1; i < nums.length; ++i) {
    //要抢劫nums[i]那么最大收益就为昨天没抢劫的最大收益，和nums[i]的和
    dp[1][i] = dp[0][i - 1] + nums[i]
    //不抢劫nums[i]那么最大收益就为昨天抢劫了或者没抢劫之中的最大值
    dp[0][i] = Math.max(dp[0][i - 1], dp[1][i - 1])
    ans = Math.max(dp[1][i], dp[0][i])
  }

  return ans
}

//重新定义状态转移方程能省去一维状态
export function rob1(nums: number[]): number {
  if (nums.length === 1) return nums[0]
  //dp[i]表示只在前i + 1家偷能获得的最大收益
  const dp: number[] = [nums[0], Math.max(nums[0], nums[1])]

  for (let i = 2; i < nums.length; ++i) {
    dp[i] = Math.max(
      // 不偷这家,那就能在[0, i-1]区间内偷
      dp[i - 1],
      //偷这家，那之前就只能在[0,i-2]区间内偷
      nums[i] + dp[i - 2]
    )
  }

  return dp[nums.length - 1]
}
