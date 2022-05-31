export function knightDialer(n: number): number {
  const MOD: number = 1_000_000_007
  const moves: number[][] = [
    [4, 6],
    [6, 8],
    [7, 9],
    [4, 8],
    [3, 9, 0],
    [],
    [1, 7, 0],
    [2, 6],
    [1, 3],
    [2, 4],
  ]

  //dp[N][start]从start起跳，跳跃了N次(N从零开始)
  const dp: number[][] = [[], []]
  dp[0] = Array.from<number>({ length: 10 }).fill(1)

  for (let jump = 0; jump < n - 1; ++jump) {
    dp[~jump & 1] = Array.from<number>({ length: 10 }).fill(0)

    for (let prev = 0; prev < 10; ++prev) {
      for (const cur of moves[prev]) {
        dp[~jump & 1][cur] += dp[jump & 1][prev]
        dp[~jump & 1][cur] %= MOD
      }
    }
  }

  let ans = 0
  for (let i = 0; i < 10; ++i) {
    ans = (ans + dp[~n & 1][i]) % MOD
  }

  return ans
}
