//记忆化搜索
export function canCross(stones: number[]): boolean {
  if (stones.length === 2) {
    if (stones[1] - stones[0] === 1) return true
    else return false
  }
  let c = stones[1] - stones[0]
  if (c > 1) return false
  const n = stones.length
  const positionToIndex = new Map()
  for (let i = 2; i < n; ++i) {
    positionToIndex.set(stones[i], i)
  }
  const memo = new Map<string, boolean>()

  const dfs = (i: number, choice: number): boolean => {
    if (i === n - 1) return true
    const memoKey = i + '-' + choice

    if (memo.has(memoKey)) return memo.get(memoKey)!

    const nextChoices = [choice - 1, choice, choice + 1]
    const curPosition = stones[i]
    for (const step of nextChoices) {
      let nextPosition = curPosition + step
      const nextIndex = positionToIndex.get(nextPosition)
      if (nextIndex && nextIndex > i) {
        if (dfs(nextIndex, step)) {
          memo.set(memoKey, true)
          return true
        }
      }
    }

    memo.set(memoKey, false)
    return false
  }

  return dfs(1, c)
}
