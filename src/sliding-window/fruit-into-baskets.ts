export function totalFruit(fruits: number[]): number {
  const window = new Map<number, number>()

  const n = fruits.length
  let l = 0
  let r = -1
  let ans = 0

  while (l < n) {
    //维护一个只有两种水果类型的窗口
    if (r + 1 < n && window.size + (window.has(fruits[r + 1]) ? 0 : 1) <= 2) {
      const t = fruits[++r]
      window.set(t, (window.get(t) ?? 0) + 1)
      ans = Math.max(r - l + 1, ans)
    } else {
      const t = fruits[l]
      const newCount = window.get(t)! - 1

      if (newCount === 0) {
        window.delete(t)
      } else {
        window.set(t, newCount)
      }

      ++l
    }
  }

  return ans
}
