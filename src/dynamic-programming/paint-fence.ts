export function numWays(n: number, k: number): number {
  if (n === 1) return k
  else if (n === 2) return k * k

  //dp[i]表示长度为i的栅栏总共的涂色数
  const dp: number[] = []
  //只有一个栅栏时，涂色方案等于颜色的数量
  dp[1] = k
  //有两个栅栏时，第一块栅栏可以选择任意k中颜色的其中一个，第二块也是
  dp[2] = k * k

  for (let i = 3; i <= n; ++i) {
    dp[i] =
      //i的颜色和i-1不同，所以i位置只有(k-1)种颜色可选，其中前k-1块栅栏总共有
      //dp[i-1]中涂色方案所以这种情况下的涂色方案有dp[i-1] * (k-1)
      dp[i - 1] * (k - 1) +
      //i的颜色和i-1相同，此时可以把i和i-1看成一个整体，此时他们必须和i-2的颜色不同
      //所以i和i-1总共有(k-1)种颜色可选所以这种情况下的涂色方案有dp[i-2] * (k-1) 
      dp[i - 2] * (k - 1)
  }

  return dp[n]
}
