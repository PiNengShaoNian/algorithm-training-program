function longestSubstring(s: string, k: number): number {
  //Impl(l, r)表示s[l:r]所代表的字串内符合条件的最长字符串长度
  const Impl = (l: number, r: number): number => {
    //如果s[l:r]字串的长度直接小于k那么是不可能在他中找到符合条件的字符串的
    //所以在这里直接返回0
    if (r - l + 1 < k) return 0

    const freq: Record<string, number> = {}

    //统计改字串内各个字符出现的频率
    for (let i = l; i <= r; ++i) {
      if (!freq[s[i]]) freq[s[i]] = 1
      else ++freq[s[i]]
    }

    //如果最左边的单词的出现频率小于k我们直接可以将左区间加1，以缩小区间大小
    while (r - l + 1 > k && freq[s[l]] < k) ++l
    //缩减右区间大小
    while (r - l + 1 > k && freq[s[r]] < k) --r

    //缩减后的区间直接小于k了，在这里直接返回零
    if (r - l + 1 < k) return 0

    for (let i = l; i <= r; ++i) {
      //该字符出现的频率小于k，他是不会出现在目标字串中的，在这里我们把他作为
      //分割中点然后在去[l,i-1]和[i + 1, r]中寻找目标
      if (freq[s[i]] < k) {
        return Math.max(Impl(l, i - 1), Impl(i + 1, r))
      }
    }

    return r - l + 1
  }

  return Impl(0, s.length - 1)
}

export function longestSubstring1(s: string, k: number): number {
  const n = s.length
  let ans = 0
  for (let t = 1; t <= 26; ++t) {
    let l = 0
    let r = -1
    let tot = 0
    let less = 0
    let cnt: Record<string, number> = {}

    while (l < n) {
      while (r + 1 < n && (tot < t || cnt[s[r + 1]] >= 1)) {
        const c = s[++r]
        cnt[c] = (cnt[c] ?? 0) + 1

        if (cnt[c] === 1) {
          ++less
          ++tot
        }

        if (cnt[c] === k) {
          --less
        }
      }

      if (less === 0) {
        ans = Math.max(ans, r - l + 1)
      }

      const c = s[l]
      ++l
      --cnt[c]

      if (cnt[c] === k - 1) {
        ++less
      }
      if (cnt[c] === 0) {
        --tot
        --less
      }
    }
  }

  return ans
}
