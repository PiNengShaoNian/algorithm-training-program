function intToRoman(num: number): string {
  const numToStr = new Map<number, string>([
    [1, 'I'],
    [4, 'IV'],
    [5, 'V'],
    [9, 'IX'],
    [10, 'X'],
    [40, 'XL'],
    [50, 'L'],
    [90, 'XC'],
    [100, 'C'],
    [400, 'CD'],
    [500, 'D'],
    [900, 'CM'],
    [1000, 'M'],
  ])

  const levels = Array.from(numToStr.keys())
  const n = levels.length
  let idx = n - 1
  let ans = ''
  while (num) {
    if (idx > 0) {
      if (num < levels[idx]) {
        idx--
      } else {
        const cnt = Math.floor(num / levels[idx])
        num %= levels[idx]
        ans += numToStr.get(levels[idx])!.repeat(cnt)
        idx--
      }
      continue
    } else {
      ans += 'I'.repeat(num)
      break
    }
  }

  return ans
}
