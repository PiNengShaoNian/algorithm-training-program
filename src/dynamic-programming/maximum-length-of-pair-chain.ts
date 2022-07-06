//LIS模板题
export function findLongestChain(pairs: number[][]): number {
  pairs.sort((a, b) => a[0] - b[0])

  const n = pairs.length
  const dp: number[] = []

  dp[0] = 1
  let ans = 1

  for (let i = 1; i < n; ++i) {
    dp[i] = 1
    for (let j = 0; j < i; ++j) {
      if (pairs[j][1] < pairs[i][0]) {
        dp[i] = Math.max(dp[i], dp[j] + 1)
      }
    }

    ans = Math.max(dp[i], ans)
  }

  return ans
}

//贪心解法
export function findLongestChain1(pairs: number[][]): number {
  //把每个区域最末端排序
  pairs.sort((a, b) => a[1] - b[1])
  let cur = -Infinity
  let ans = 0
  for (const pair of pairs) {
    //这里每次选择的pair都是末端最靠前的那个区域
    if (cur < pair[0]) {
      cur = pair[1]
      ++ans
    }
  }

  return ans
}
