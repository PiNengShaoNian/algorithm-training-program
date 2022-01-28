export function findRepeatedDnaSequences(s: string): string[] {
  const n = s.length

  if (n < 10) return []

  const ans = new Set<string>()
  const set = new Set<string>()
  for (let i = 0; i + 10 <= n; ++i) {
    const substr = s.slice(i, i + 10)

    if (set.has(substr)) {
      ans.add(substr)
    } else {
      set.add(substr)
    }
  }

  return Array.from(ans)
}

export function findRepeatedDnaSequences1(s: string): string[] {
  const n = s.length
  const L = 10

  if (n < L) return []
  const map: Record<string, number> = {
    A: 0b00,
    C: 0b01,
    G: 0b10,
    T: 0b11,
  }
  let x = 0
  const ans: string[] = []

  for (let i = 0; i < L - 1; ++i) {
    x = (x << 2) | map[s[i]]
  }

  const cnt: Record<number, number> = {}
  for (let i = L - 1; i < n; ++i) {
    x = ((x << 2) | map[s[i]]) & ((1 << (2 * L)) - 1)
    cnt[x] = (cnt[x] ?? 0) + 1

    if (cnt[x] === 2) {
      ans.push(s.slice(i - L + 1, i + 1))
    }
  }

  return ans
}
