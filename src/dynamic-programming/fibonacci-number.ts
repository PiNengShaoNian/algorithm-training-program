export function fib(n: number): number {
  if (n === 0) return 0
  let minusTwo = 0
  let minusOne = 1

  for (let i = 2; i <= n; ++i) {
    const temp = minusOne + minusTwo
    minusTwo = minusOne
    minusOne = temp
  }

  return minusOne
}
