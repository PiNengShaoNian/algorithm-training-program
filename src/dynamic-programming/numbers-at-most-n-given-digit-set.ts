export function atMostNGivenDigitSet(digits: string[], n: number): number {
  const K = n.toString().length
  //dp[i]表示和数字n[i:K)位数相同但是比n小的数字的数量
  //加入n为2345，dp[3]就表示位数为1比5小的数字数量，dp[2]表示位数
  //为2但是比45小的数字数量，dp[1]表示位数为3且比345小的数字数量
  const dp: number[] = Array.from<number>({ length: K + 1 }).fill(0)
  dp[K] = 1
  const numDigits = [...n.toString()].map((v) => +v)
  const digits1 = digits.map((v) => +v)
  const dLen = digits.length

  //计算和n有相同位数但是比n小的数的个数
  for (let i = K - 1; i >= 0; --i) {
    const si = numDigits[i]

    let count = 0
    for (let j = 0; j < dLen; ++j) {
      const d = digits1[j]
      if (d < si) {
        count += digits.length ** (K - i - 1)
      } else if (d === si) {
        count += dp[i + 1]
      }
    }

    dp[i] = count
  }

  //计算位数比n小的数的个数(位数比n小，则一定比n小)
  for (let i = 1; i < K; ++i) {
    dp[0] += digits.length ** i
  }

  return dp[0]
}
