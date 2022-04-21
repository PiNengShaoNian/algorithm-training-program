export function countArrangement(n: number): number {
  let ans = 0
  let used: number = 0

  const matched: number[][] = []

  //提前预处理出i位置可以放那些数
  for (let i = 1; i <= n; ++i) {
    matched[i] = []
    for (let j = 1; j <= n; ++j) {
      if (j % i === 0 || i % j === 0) {
        matched[i].push(j)
      }
    }
  }

  //Impl(idx)表示，尝试在idx位置放置符合的数
  const Impl = (idx: number): void => {
    if (idx === n + 1) {
      ++ans
      return
    }

    for (const i of matched[idx]) {
      if ((used & (1 << i)) === 0) {
        // perm[i] = i,i = idx
        used ^= 1 << i
        Impl(idx + 1)
        used ^= 1 << i
      }
    }
  }

  Impl(1)

  return ans
}
