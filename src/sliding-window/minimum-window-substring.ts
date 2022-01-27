export function minWindow(s: string, t: string): string {
  let count = t.length
  const n = s.length
  const need: Record<string, number> = {}

  for (let i = 0; i < count; ++i) {
    need[t[i]] = (need[t[i]] ?? 0) + 1
  }

  let l = 0
  let r = -1
  let min = Infinity
  let ans = ''

  while (l < n) {
    while (r + 1 < n && count !== 0) {
      const c = s[++r]
      if (c in need && need[c]-- > 0) {
        --count
      }
    }

    if (count === 0 && r - l + 1 < min) {
      ans = s.slice(l, r + 1)
      min = r - l + 1
    }

    const c = s[l]
    ++l
    if (c in need && ++need[c] > 0) {
      ++count
    }
  }

  return ans
}
