function isValidSerialization(preorder: string): boolean {
  const tokens = preorder.split(',')
  let i = 0
  const n = tokens.length
  const stk = [1]
  while (i < n) {
    if (!stk.length) {
      return false
    }
    if (tokens[i] === '#') {
      stk[stk.length - 1]--
      if (stk[stk.length - 1] === 0) {
        stk.pop()
      }
      i++
    } else {
      stk[stk.length - 1]--
      if (stk[stk.length - 1] === 0) {
        stk.pop()
      }
      stk.push(2)
      i++
    }
  }

  return stk.length === 0
}
