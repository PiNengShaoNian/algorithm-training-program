export function xorQueries(arr: number[], queries: number[][]): number[] {
  const prefix: number[] = []
  const n = arr.length
  const m = queries.length
  prefix[0] = 0

  for (let i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] ^ arr[i]
  }

  const ans: number[] = []

  for (let i = 0; i < m; ++i) {
    const [l, r] = queries[i]

    ans[i] = prefix[r + 1] ^ prefix[l]
  }

  return ans
}
