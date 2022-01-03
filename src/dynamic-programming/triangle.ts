//正着推
export function minimumTotal(triangle: number[][]): number {
  const n = triangle.length
  const m = triangle[triangle.length - 1].length
  const dp: number[][] = []
  for (let i = 0; i < n; ++i) {
    dp[i] = []
  }
  dp[0][0] = triangle[0][0]

  for (let i = 1; i < n; ++i) {
    const line = triangle[i]
    for (let j = 0; j < line.length; ++j) {
      dp[i][j] =
        Math.min(dp[i - 1][j] ?? Infinity, dp[i - 1][j - 1] ?? Infinity) +
        line[j]
    }
  }

  let ans = Infinity

  for (let i = 0; i < m; ++i) {
    ans = Math.min(ans, dp[n - 1][i])
  }

  return ans
}

//倒着推
export function minimumTotal1(triangle: number[][]): number {
  if (!triangle.length) return 0

  for (let depth = triangle.length - 2; depth >= 0; --depth) {
    for (let i = 0; i < triangle[depth].length; ++i) {
      triangle[depth][i] =
        triangle[depth][i] +
        Math.min(triangle[depth + 1][i], triangle[depth + 1][i + 1])
    }
  }

  return triangle[0][0]
}
