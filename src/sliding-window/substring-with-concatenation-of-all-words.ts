export function findSubstring(s: string, words: string[]): number[] {
  const isSame = (
    map1: Map<string, number>,
    map2: Map<string, number>
  ): boolean => {
    if (map1.size !== map2.size) return false

    for (const key of map1.keys()) {
      if (map1.get(key) !== map2.get(key)) return false
    }

    return true
  }
  const n = s.length
  const wlen = words[0].length
  const m = words.length * wlen
  const count: Map<string, number> = new Map()
  const ans = new Set<number>()
  for (let i = 0; i < words.length; ++i) {
    count.set(words[i], (count.get(words[i]) ?? 0) + 1)
  }

  for (let i = 0; i < wlen; ++i) {
    let l = i
    let r = l - wlen
    const window: Map<string, number> = new Map()

    while (l < n && r < n) {
      if (r - l + wlen < m) {
        while (r - l + wlen < m) {
          const word = s.substr(r + wlen, wlen)
          window.set(word, (window.get(word) ?? 0) + 1)
          r += wlen
        }
      } else {
        const leftWord = s.substr(l, wlen)
        const newCount = window.get(leftWord)! - 1
        if (!newCount) {
          window.delete(leftWord)
        } else {
          window.set(leftWord, newCount)
        }

        l += wlen
        r += wlen

        const rightWord = s.substr(r, wlen)
        window.set(rightWord, (window.get(rightWord) ?? 0) + 1)
      }

      if (isSame(count, window)) {
        ans.add(l)
      }
    }
  }

  return Array.from(ans)
}
