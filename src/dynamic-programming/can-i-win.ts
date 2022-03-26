function canIWin(maxChoosableInteger: number, desiredTotal: number): boolean {
  if (maxChoosableInteger >= desiredTotal) return true
  if ((maxChoosableInteger * (maxChoosableInteger + 1)) / 2 < desiredTotal)
    return false

  const memo: boolean[] = []
  /**
   * 
   * @param state 已经选择了哪些数字 比如0b0110表示选择了数字1和数字2
   * @param remaining 还剩下的目标和
   * @returns 
   */
  const Impl = (state: number, remaining: number): boolean => {
    if (memo[state] !== undefined) return memo[state]

    for (let i = 1; i <= maxChoosableInteger; ++i) {
      const cur = 1 << i

      if ((cur & state) !== 0) {
        continue
      }

      if (i >= remaining || Impl(state | cur, remaining - i) === false) {
        return (memo[state] = true)
      }
    }

    return (memo[state] = false)
  }

  return Impl(0, desiredTotal)
}
