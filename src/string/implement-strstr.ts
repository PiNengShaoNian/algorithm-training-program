//Rabin-Karp 滚动哈希
export function strStr(s: string, t: string): number {
  const n = s.length
  const m = t.length
  const base = 13331
  const mod = 9999991
  let tHash = 0
  s = ' ' + s
  t = ' ' + t

  for (let i = 1; i <= m; ++i) {
    tHash = (tHash * base + t.charCodeAt(i)) % mod
  }

  let sHash: number[] = []
  let p13331: number[] = []
  p13331[0] = 1
  sHash[0] = 0
  for (let i = 1; i <= n; ++i) {
    sHash[i] = (sHash[i - 1] * base + s.charCodeAt(i)) % mod
    p13331[i] = (p13331[i - 1] * base) % mod
  }

  const calcHash = (l: number, r: number): number => {
    return (((sHash[r] - sHash[l - 1] * p13331[r - l + 1]) % mod) + mod) % mod
  }

  for (let i = m; i <= n; ++i) {
    if (
      calcHash(i - m + 1, i) === tHash &&
      s.substring(i - m + 1, i + 1) === t.substring(1)
    )
      return i - m
  }

  return -1
}
