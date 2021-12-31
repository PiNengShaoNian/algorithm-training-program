export function ways(pizza: string[], k: number): number {
  const presum: number[][] = []
  const n = pizza.length
  const m = pizza[0].length
  const mod = 1e9 + 7
  const memo: number[][][] = []

  for (let i = 0; i < n; ++i) {
    memo[i] = []
    for (let j = 0; j < m; ++j) {
      memo[i][j] = []
    }
  }

  for (let i = 0; i <= n; ++i) {
    presum[i] = []
    presum[i][m] = 0
  }

  for (let i = 0; i <= m; ++i) {
    presum[n][i] = 0
  }

  for (let i = n - 1; i >= 0; --i) {
    for (let j = m - 1; j >= 0; --j) {
      presum[i][j] =
        (pizza[i][j] === 'A' ? 1 : 0) +
        presum[i + 1][j] +
        presum[i][j + 1] -
        presum[i + 1][j + 1]
    }
  }

  const Impl = (row: number, col: number, remain: number): number => {
    if (remain === 0) {
      return presum[row][col] ? 1 : 0
    }

    if (typeof memo[row][col][remain] === 'number')
      return memo[row][col][remain]

    let ans = 0
    for (let i = row + 1; i < n; ++i) {
      if (presum[row][col] === presum[i][col]) continue

      ans = (ans + Impl(i, col, remain - 1)) % mod
    }

    for (let i = col + 1; i < m; ++i) {
      if (presum[row][col] === presum[row][i]) continue

      ans = (ans + Impl(row, i, remain - 1)) % mod
    }

    return (memo[row][col][remain] = ans)
  }

  return Impl(0, 0, k - 1)
}
