export function distinctSubseqII(s: string): number {
  const dp: number[] = []
  const last: number[] = Array.from<number>({ length: 26 }).fill(-1)
  const offset = 97
  const n = s.length
  dp[0] = 1
  const mod = 1000000007

  for (let i = 1; i <= n; ++i) {
    const x = s.charCodeAt(i - 1) - offset
    dp[i] = (dp[i - 1] * 2) % mod

    if (last[x] >= 0) {
      dp[i] -= dp[last[x]]
    }

    dp[i] %= mod
    last[x] = i - 1
  }

  --dp[n]

  if (dp[n] < 0) dp[n] += mod

  return dp[n]
}
