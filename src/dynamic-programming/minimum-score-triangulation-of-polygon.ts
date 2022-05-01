function minScoreTriangulation(values: number[]): number {
  const n = values.length

  //dp[i][j]表示由values[i:j]区间内的顶点构成的多边形能获得的最小分数
  const dp: number[][] = []

  for (let i = 0; i < n; ++i) {
    dp[i] = Array.from<number>({ length: n }).fill(0)
  }

  //通过枚举i,j而遍历到所有多边形values[i:j]，然后我们再在一个多边形values[i,j]
  //中把顶定i,j当作一个三角形的底部两个端点，我们再在values[i+1:j-1]中枚举三角
  //形的顶部端点m,这时候这个多边形就会被分为三部分: 多边形values[i:m],三角形
  //(i,m,j),多边形values[m:j],所以多边形values[i:j]的最低分数就为
  //dp[i][j] = min(dp[i][m] + values[i] * values[m] * values[j] + dp[m][j])
  //其中m的范围为[i+1,j-1]
  for (let i = n - 3; i >= 0; --i) {
    for (let j = i + 2; j < n; ++j) {
      for (let m = i + 1; m < j; ++m) {
        if (!dp[i][j]) {
          dp[i][j] = values[i] * values[j] * values[m] + dp[i][m] + dp[m][j]
        } else {
          dp[i][j] = Math.min(
            dp[i][j],
            values[i] * values[j] * values[m] + dp[i][m] + dp[m][j]
          )
        }
      }
    }
  }

  return dp[0][n - 1]
}
