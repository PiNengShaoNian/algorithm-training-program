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
