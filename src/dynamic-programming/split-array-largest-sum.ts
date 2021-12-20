//动态规划解法时间复杂度O(N ^ 2 * m)
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

//动态规划解法O(N * log(10 ^ 9))
export function splitArray1(nums: number[], m: number): number {
  let right = 10 ** 9
  let left = 0

  while (left <= right) {
    //枚举最大的子数组和为mid
    const mid = (right + left) >> 1

    let count = 1
    let sum = 0
    //算出以mid为子数组和能将数组分割为几个子数组
    for (let i = 0; i < nums.length; ++i) {
      //如果nums[i]大于mid说明子数组和太小无法分割
      if (nums[i] > mid) {
        count = Infinity
        break
      }
      if (sum + nums[i] > mid) {
        ++count
        sum = nums[i]
      } else {
        sum += nums[i]
      }
    }

    //该mid能分割出答案,尝试更小的mid
    if (count <= m) {
      right = mid - 1
    } else {
      left = mid + 1
    }
  }

  return left
}
