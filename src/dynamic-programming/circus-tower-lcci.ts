//LIS一样的思路
export function bestSeqAtIndex(height: number[], weight: number[]): number {
  const pairs: number[][] = height.map((h, i) => [h, weight[i]])
  pairs.sort((a, b) => {
    if (a[0] !== b[0]) return a[0] - b[0]

    return b[1] - a[1]
  })
  const n = pairs.length
  const ans: number[] = []

  for (let i = 0; i < n; ++i) {
    const w = pairs[i][1]
    let l = 0
    let r = ans.length - 1
    let p = ans.length

    while (l <= r) {
      const mid = l + ((r - l) >> 1)

      if (ans[mid] > w) {
        r = mid - 1
        p = mid
      } else if (ans[mid] < w) {
        p = l = mid + 1
      } else {
        r = mid - 1
        p = mid
      }
    }

    if (p < ans.length) {
      ans[p] = w
    } else {
      ans.push(w)
    }
  }

  return ans.length
}
