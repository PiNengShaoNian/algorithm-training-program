export function removeKdigits(num: string, k: number): string {
  const stack: number[] = []

  for (const c of num) {
    //保证去除掉若干字符的数字是递增的，这样形成的数字最小
    while (stack.length && stack[stack.length - 1] > +c && k) {
      --k
      stack.pop()
    }

    stack.push(+c)
  }

  for (let i = 0; i < k; ++i) {
    stack.pop()
  }

  let isLeadingZero = true
  let ans = ''
  for (const num of stack) {
    //去掉前置零
    if (isLeadingZero && num === 0) {
      continue
    }

    isLeadingZero = false
    ans += num
  }

  return !ans ? '0' : ans
}
