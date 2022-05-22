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
  //dfs(curNeeds)表示，当前要完成当前购买清单需要的最低价格
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
        //状态转移dfs(nextNeeds) = Math.min(dfs(nextNeeds), curSpecial[n] + dfs(nextNeeds))
        minPrice = Math.min(minPrice, dfs(nextNeeds) + curSpecial[n])
      }
    }

    memo.set(key, minPrice)
    return minPrice
  }

  return dfs(needs)
}
