function stoneGameII(piles: number[]): number {
  //dp[i][j]表示只存在piles[i:n-1]堆石头时，当前的M为j，该先手玩家能获得的最大石子
  const dp: number[][] = []
  const n = piles.length
  let sum = 0
  for (let i = 0; i < n; ++i) {
    dp[i] = Array.from<number>({ length: n + 1 }).fill(0)
  }

  for (let i = n - 1; i >= 0; --i) {
    sum += piles[i]

    for (let M = 1; M <= n; ++M) {
      if (i + 2 * M >= n) {
        //能进入着说明先手玩家能够把所有的石子全部收入囊中，所以dp[i][M]就为sum
        dp[i][M] = sum
      } else {
        for (let X = 1; X <= 2 * M; ++X) {
          dp[i][M] = Math.max(dp[i][M], 
            //不能拿走所有堆的石头那就先拿走X堆石头，然后第二个玩家会在piles[i+X:n-1]区间做出他的最优
            //选择获得dp[i+X][Math.max(M,X)]个石头，所以先手玩家能获得的最大石子就是
            //sum - dp[i + X][Math.max(M,X)]
            sum - dp[i + X][Math.max(M, X)])
        }
      }
    }
  }

  return dp[0][1]
}
