function nthUglyNumber(n: number): number {
  let i2 = 1
  let i3 = 1
  let i5 = 1
  const dp: number[] = []
  dp[1] = 1
  //根据题目要求丑数只包含质因数 2、3 和/或 5,所以我们
  //可以从1开始不断的从小丑数往后构建出大丑数
  for (let i = 2; i <= n; ++i) {
    let nextTwo = dp[i2] * 2
    let nextThree = dp[i3] * 3
    let nextFive = dp[i5] * 5

    const min = Math.min(nextTwo, nextThree, nextFive)

    if (min === nextTwo) {
      ++i2
    }
    if (min === nextThree) {
      ++i3
    }
    if (min === nextFive) {
      ++i5
    }

    dp[i] = min
  }

  return dp[n]
}
