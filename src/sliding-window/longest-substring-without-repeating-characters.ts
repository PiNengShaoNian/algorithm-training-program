type char = string

function lengthOfLongestSubstring(s: string): number {
  const window: Set<char> = new Set()

  let r = -1
  let l = 0
  let ans = 0
  while (l < s.length) {
    if (r + 1 < s.length && !window.has(s[r + 1])) {
      window.add(s[++r])

      ans = Math.max(ans, r - l + 1)
    } else {
      window.delete(s[l])
      ++l
    }
  }

  return ans
}
