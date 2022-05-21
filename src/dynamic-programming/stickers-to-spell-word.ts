function minStickers(stickers: string[], target: string): number {
  const memo: number[] = [0]
  const n = target.length
  const m = stickers.length

  //dp(mask)表示构成该mask子序列需要的最少贴纸数量
  const dp = (mask: number): number => {
    if (memo[mask] !== undefined) return memo[mask]
    let res = n + 1
    for (let i = 0; i < m; ++i) {
      const sticker = stickers[i]
      const cnt = new Int32Array(26)
      const stickerLen = sticker.length
      for (let j = 0; j < stickerLen; ++j) {
        ++cnt[sticker.charCodeAt(j) - 97]
      }

      let left = mask
      for (let j = 0; j < n; ++j) {
        const char = target[j]
        if (mask & (1 << j) && cnt[char.charCodeAt(0) - 97]) {
          --cnt[char.charCodeAt(0) - 97]
          left ^= 1 << j
        }
      }

      if (left < mask) {
        res = Math.min(res, dp(left) + 1)
      }
    }

    return (memo[mask] = res)
  }

  const res = dp((1 << n) - 1)

  return res <= n ? res : -1
}
