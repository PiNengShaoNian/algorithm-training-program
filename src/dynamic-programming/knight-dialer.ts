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

  //dp[start][N]表示从start起跳，在跳跃了N次后总共组成号码的个数
  const dp: number[][] = [[], []]

  //N为零，对于输入n为1时，也就是只需要在每个起点跳跃零次就能满足需求
  dp[0] = Array.from<number>({ length: 10 }).fill(1)

  for (let jump = 0; jump < n - 1; ++jump) {
    dp[~jump & 1] = Array.from<number>({ length: 10 }).fill(0)
    for (let num = 0; num < 10; ++num) {
      for (const neighbor of moves[num]) {
        dp[~jump & 1][neighbor] += dp[jump & 1][num]
        dp[~jump & 1][neighbor] %= MOD
      }
    }
  }

  let ans = 0

  for (let i = 0; i < 10; ++i) {
    ans += dp[~n & 1][i] % MOD
  }

  return ans % MOD
}
