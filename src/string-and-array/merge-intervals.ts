function merge(intervals: number[][]): number[][] {
  intervals.sort((a, b) => a[0] - b[0])
  const n = intervals.length

  let idx = 1
  const ans = [intervals[0]]
  while (idx < n) {
    const prev = ans[ans.length - 1]
    const curr = intervals[idx]
    if (prev[1] >= curr[0]) {
      prev[1] = Math.max(prev[1], curr[1])
    } else {
      ans.push(curr)
    }

    idx++
  }

  return ans
}
