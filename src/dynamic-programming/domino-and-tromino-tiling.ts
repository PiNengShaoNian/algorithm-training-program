export function numTilings(n: number): number {
  const MOD = 1e9 + 7

  let dp: number[] = [1, 0, 0, 0]
  for (let i = 0; i < n; ++i) {
    const ndp: number[] = []

    ndp[0b00] = (dp[0b00] + dp[0b11]) % MOD
    ndp[0b01] = (dp[0b00] + dp[0b10]) % MOD
    ndp[0b10] = (dp[0b00] + dp[0b01]) % MOD
    ndp[0b11] = (dp[0b00] + dp[0b10] + dp[0b01]) % MOD

    dp = ndp
  }

  return dp[0]
}
