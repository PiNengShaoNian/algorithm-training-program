function lengthLongestPath(input: string): number {
  const lines = input.split('\n')
  const stack: number[] = []
  let ans = 0
  let level = 0
  for (const word of lines) {
    const validWord = word.replace(/^\t*/, '')
    level = word.length - validWord.length
    if (stack.length <= level) {
      stack.push(validWord.length)
    } else {
      stack[level] = validWord.length
    }
    if (level > 0) {
      stack[level] += stack[level - 1]
    }

    if (validWord.includes('.')) {
      ans = Math.max(ans, stack[level] + level)
    }
  }

  return ans
}
