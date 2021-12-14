export const oddEvenJumps = (arr: number[]): number => {
  const n = arr.length
  const order: number[] = new Array(n).fill(0).map((_, i) => i)
  const stack: number[] = []
  const odd: number[] = []
  const even: number[] = []
  const res = new Array(n).fill(0).map(() => [1, 0])

  order.sort((i, j) => {
    if (arr[i] !== arr[j]) {
      return arr[i] - arr[j]
    }
    return i - j
  })

  for (let i = 0; i < n; i++) {
    while (stack.length && stack[stack.length - 1] < order[i]) {
      const top = stack.pop()!
      odd[top] = order[i]
    }
    stack.push(order[i])
  }
  while (stack.length) {
    const top = stack.pop()!
    odd[top] = -1
  }

  order.sort((i, j) => {
    if (arr[i] !== arr[j]) {
      return arr[j] - arr[i]
    }
    return i - j
  })

  for (let i = 0; i < n; i++) {
    while (stack.length && stack[stack.length - 1] < order[i]) {
      const top = stack.pop()!
      even[top] = order[i]
    }
    stack.push(order[i])
  }
  while (stack.length) {
    const top = stack.pop()!
    even[top] = -1
  }

  for (let i = 0; i < n; i++) {
    if (odd[i] !== -1) {
      res[odd[i]][1] += res[i][0]
    }
    if (even[i] !== -1) {
      res[even[i]][0] += res[i][1]
    }
  }

  return res[n - 1][0] + res[n - 1][1]
}
