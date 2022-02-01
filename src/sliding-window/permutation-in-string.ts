function checkInclusion(s1: string, s2: string): boolean {
  const len1 = s1.length
  const len2 = s2.length

  if (len2 < len1) return false

  const targetCnt: Record<string, number> = {}

  for (let i = 0; i < len1; ++i) {
    targetCnt[s1[i]] = (targetCnt[s1[i]] ?? 0) + 1
  }

  const cnt: Record<string, number> = {}

  let l = 0
  let r = -1

  let notMeet = Object.keys(targetCnt).length
  while (l < len2) {
    while (r - l + 1 < len1) {
      const c = s2[++r]
      cnt[c] = (cnt[c] ?? 0) + 1

      if (cnt[c] === targetCnt[c]) --notMeet
    }

    if (!notMeet) {
      return true
    }

    const c = s2[l]
    cnt[c] = cnt[c] - 1

    if (cnt[c] === targetCnt[c] - 1) {
      ++notMeet
    }
    ++l
  }

  return false
}
