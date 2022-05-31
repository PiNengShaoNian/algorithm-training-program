//简单模拟,时间复杂度O(rows * cols)
export function wordsTyping(
  sentence: string[],
  rows: number,
  cols: number
): number {
  let wLen = sentence.length
  let wIdx = 0
  let ans = 0
  for (let i = 0; i < rows; ++i) {
    let col = 0

    while (col < cols) {
      const len = sentence[wIdx].length
      if (cols - col >= len) {
        ++wIdx
        col += len + 1

        if (wIdx === wLen) {
          ++ans
          wIdx = 0
        }
      } else {
        break
      }
    }
  }

  return ans
}

//动态规划,时间复杂度O(sentence.length * cols + rows)
export function wordsTyping1(
  sentence: string[],
  rows: number,
  cols: number
): number {
  const n = sentence.length
  //dp[i]表示，开始单词为sentence[i],改行能放下几个sentence
  const dp: number[] = []
  // 从第 i 个词开始 放下dp[i]遍句子后 变为第几个词
  const next: number[] = []

  for (let i = 0; i < n; ++i) {
    let cur = cols
    let wIdx = i
    let count = 0
    while (cur >= sentence[wIdx].length) {
      cur -= sentence[wIdx].length + 1
      ++wIdx
      if (wIdx === n) {
        wIdx = 0
        ++count
      }
    }

    dp[i] = count
    next[i] = wIdx
  }

  let ans = 0

  let cur = 0
  for (let i = 0; i < rows; ++i) {
    ans += dp[cur]
    cur = next[cur]
  }

  return ans
}
