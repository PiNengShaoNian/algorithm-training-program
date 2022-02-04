function characterReplacement(s: string, k: number): number {
  const n = s.length
  const fre: number[] = Array.from<number>({ length: 26 }).fill(0)

  let l = 0
  let r = 0
  //maxn表示s[l:r-1]区间内出现次数最多字符的出现次数
  let maxn = 0
  let ans = 0

  while (r < n) {
    ++fre[s.charCodeAt(r) - 65]
    //显然在k(替换次数)不变的情况下，只有maxn变大的情况下才会贡献新的答案
    maxn = Math.max(maxn, fre[s.charCodeAt(r) - 65])
    ++r

    if (r - l > maxn + k) {
      //这里右移左边界时可能会出现maxn变小的情况，
      //但是我们完全没必要费工夫去更新maxn了
      //因为更小的maxn不会对最终答案有什么影响
      --fre[s.charCodeAt(l) - 65]
      ++l
    }

    ans = Math.max(ans, r - l)
  }

  return ans
}
