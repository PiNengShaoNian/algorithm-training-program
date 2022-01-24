export function longestDecomposition(text: string): number {
  const Impl = (s: string): number => {
    const n = s.length

    for (let i = 1; i <= n >> 1; ++i) {
      if (s.substr(0, i) === s.substr(n - i, i)) {
        return Impl(s.substring(i, n - i)) + 2
      }
    }

    return n > 0 ? 1 : 0
  }

  return Impl(text)
}

//用字符串hash思路解题的全部都用bigint,不然跑不过测试
export function longestDecomposition1(text: string): number {
  const Impl = (s: string, l: bigint, r: bigint): number => {
    const n = r - l + 1n
    const base = 131n
    let hashL = 0n
    let hashR = 0n
    let pow131 = 1n
    for (let i = 1n; i <= n >> 1n; ++i) {
      //由高位向低位算hash值
      hashL = hashL * base + BigInt(s.charCodeAt(Number(l + i - 1n)))
      //由低位向高位算hash值
      hashR = hashR + BigInt(s.charCodeAt(Number(r - i + 1n))) * pow131
      pow131 *= base

      if (hashL === hashR) {
        return 2 + Impl(text, l + i, r - i)
      }
    }

    return n > 0 ? 1 : 0
  }

  return Impl(text, 0n, BigInt(text.length - 1))
}
