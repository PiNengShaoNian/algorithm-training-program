export function findAnagrams(s: string, p: string): number[] {
  if (s.length < p.length) return []

  const freS = Array.from<number>({ length: 26 }).fill(0)
  const freP = Array.from<number>({ length: 26 }).fill(0)

  for (let i = 0; i < p.length; ++i) {
    ++freP[p.charCodeAt(i) - 97]
  }

  let l = 0
  let r = -1
  const n = s.length
  const ans: number[] = []
  while (l < n) {
    if (r - l + 1 < p.length) {
      ++freS[s.charCodeAt(++r) - 97]
    } else {
      --freS[s.charCodeAt(l) - 97]
      ++l
      ++freS[s.charCodeAt(++r) - 97]
    }

    let isSame = true

    for (let i = 0; i < freS.length; ++i) {
      if (freS[i] !== freP[i]) {
        isSame = false
        break
      }
    }

    if (isSame) {
      ans.push(l)
    }
  }

  return ans
}
