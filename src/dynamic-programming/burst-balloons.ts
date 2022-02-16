export function maxCoins(nums: number[]): number {
  const n = nums.length
  nums.unshift(1)
  nums.push(1)
  const memo: number[][] = []

  for (let i = 0; i <= n; ++i) {
    memo[i] = []
  }

  const Impl = (l: number, r: number): number => {
    if (l > r) return 0

    if (typeof memo[l][r] === 'number') return memo[l][r]

    let ans = 0

    for (let i = l; i <= r; ++i) {
      ans = Math.max(
        ans,
        Impl(l, i - 1) + Impl(i + 1, r) + nums[l - 1] * nums[r + 1] * nums[i]
      )
    }

    return (memo[l][r] = ans)
  }

  return Impl(1, n)
}
