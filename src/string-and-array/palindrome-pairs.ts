const isPalindrome = (str: string): boolean => {
  let l = 0,
    r = str.length - 1
  while (l < r) {
    if (str[l++] != str[r--]) return false // 我很不想这么写，尽量一句话做一件事吧
  }
  return true
}
const palindromePairs = (words: string[]): number[][] => {
  const reverseds = new Map<string, number>()
  for (let i = 0; i < words.length; i++) {
    const reversed = words[i].split('').reverse().join('')
    reverseds.set(reversed, i)
  }
  const res: number[][] = []
  for (let i = 0; i < words.length; i++) {
    const curWord = words[i]
    if (isPalindrome(curWord) && reverseds.has('') && curWord !== '') {
      res.push([reverseds.get('')!, i])
    }
    for (let j = 0; j < curWord.length; j++) {
      const left = curWord.substring(0, j)
      const right = curWord.substring(j)
      if (
        isPalindrome(left) &&
        reverseds.has(right) &&
        reverseds.get(right) !== i
      ) {
        res.push([reverseds.get(right)!, i])
      }
      if (
        isPalindrome(right) &&
        reverseds.has(left) &&
        reverseds.get(left) !== i
      ) {
        res.push([i, reverseds.get(left)!])
      }
    }
  }
  return res
}
