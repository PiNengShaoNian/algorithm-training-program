//动态规划解法，和LIS差不多的思路
export function bestTeamScore(scores: number[], ages: number[]): number {
  const pairs = scores.map((s, i) => [s, ages[i]])

  pairs.sort((a, b) => {
    //按分数进行升序排序，在对排序后的序列按年龄求最长子序列这样选出来的人的分数就能保证是最大的
    //而且他们之间不会冲突
    if (a[0] !== b[0]) return a[0] - b[0]
    //如果两个人的分数一样，就按照他们的年龄进行升序排序，这样能保证的出来的子序列
    //更长
    return a[1] - b[1]
  })

  //dp[i]表示以pairs[i]为结尾的子数组pairs[0:i]中能获得的最大分数为多少
  //其实就是求子数组中年龄的最大上升子序列长度
  const dp: number[] = []
  dp[0] = pairs[0][0]
  const n = scores.length
  let ans = dp[0]
  
  //LIS模板
  for (let i = 1; i < n; ++i) {
    dp[i] = pairs[i][0]
    for (let j = 0; j < i; ++j) {
      if (pairs[j][1] <= pairs[i][1]) {
        dp[i] = Math.max(dp[i], dp[j] + pairs[i][0])
      }
    }
    ans = Math.max(ans, dp[i])
  }

  return ans
}
