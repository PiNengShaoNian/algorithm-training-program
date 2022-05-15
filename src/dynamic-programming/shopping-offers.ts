export function shoppingOffers(
  price: number[],
  special: number[][],
  needs: number[]
): number {
  const n = price.length
  const sLen = special.length
  const filterSpecial: number[][] = []
  const memo = new Map<string, number>()

  for (let i = 0; i < sLen; ++i) {
    const s = special[i]
    let totalPrice = 0
    let totalCount = 0
    for (let j = 0; j < n; ++j) {
      totalCount += s[j]
      totalPrice += price[j] * s[j]
    }

    if (totalCount === 0 || s[n] >= totalPrice) {
      continue
    }
    filterSpecial.push(s)
  }

  const fsLen = filterSpecial.length
  const dfs = (curNeeds: number[]): number => {
    const key = curNeeds.join('-')
    if (memo.has(key)) return memo.get(key)!
    let minPrice = 0

    for (let i = 0; i < n; ++i) {
      minPrice += price[i] * curNeeds[i]
    }
    for (let i = 0; i < fsLen; ++i) {
      const curSpecial = filterSpecial[i]
      const nextNeeds: number[] = []
      for (let j = 0; j < n; ++j) {
        if (curNeeds[j] < curSpecial[j]) break

        nextNeeds.push(curNeeds[j] - curSpecial[j])
      }

      if (nextNeeds.length === n) {
        minPrice = Math.min(minPrice, dfs(nextNeeds) + curSpecial[n])
      }
    }

    memo.set(key, minPrice)
    return minPrice
  }

  return dfs(needs)
}
