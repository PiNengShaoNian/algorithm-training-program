export function tribonacci(n: number): number {
  if (n === 0) return 0
  else if (n === 1) return 1
  else if (n === 2) return 1

  let minusThree = 0
  let minusTwo = 1
  let minusOne = 1

  for (let i = 3; i <= n; ++i) {
    const temp = minusOne + minusTwo + minusThree
    minusThree = minusTwo
    minusTwo = minusOne
    minusOne = temp
  }

  return minusOne
}
