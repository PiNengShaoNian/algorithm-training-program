export function lenLongestFibSubseq(arr: number[]): number {
  let ans = 0
  const n = arr.length
  const set = new Set(arr)
  for (let i = 0; i < n; ++i) {
    for (let j = i + 1; j < n; ++j) {
      let one = arr[i]
      let two = arr[j]
      let length = 2

      while (set.has(one + two)) {
        const t = one + two
        one = two
        two = t
        ans = Math.max(ans, ++length)
      }
    }
  }

  return ans >= 3 ? ans : 0
}

//动态规划解法时间复杂度O(N^2)
export function lenLongestFibSubseq1(arr: number[]): number {
  const numToIndex = new Map<number, number>()
  const n = arr.length
  for (let i = 0; i < n; ++i) {
    numToIndex.set(arr[i], i)
  }

  // dp.get(i * n + j)其中i < j表示以arr[i] + arr[j]为尾项的斐波那契序列长度为dp.get(i * n + j) - 2
  const dp = new Map<number, number>()

  let ans = 0
  for (let i = 0; i < n; ++i) {
    for (let j = 0; j < i; ++j) {
      if (arr[i] - arr[j] < arr[j] && numToIndex.has(arr[i] - arr[j])) {
        const first = numToIndex.get(arr[i] - arr[j])!

        dp.set(j * n + i, (dp.get(first * n + j) ?? 0) + 1)
        ans = Math.max(ans, dp.get(j * n + i)! + 2)
      }
    }
  }

  return ans >= 3 ? ans : 0
}
