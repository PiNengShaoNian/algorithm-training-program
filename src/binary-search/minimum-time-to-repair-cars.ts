function repairCars(ranks: number[], cars: number): number {
  let l = 1
  let r = Number.MAX_SAFE_INTEGER
  const n = ranks.length
  const canRepair = (min: number): boolean => {
    let ans = 0

    for (let i = 0; i < n; i++) {
      const rank = ranks[i]
      // 已知: min = rank * n ^ 2; 求: n
      // n = Math.sqrt(min / rank)
      ans += Math.floor(Math.sqrt(min / rank))
      if (ans >= cars) {
        return true
      }
    }

    return false
  }

  let ans = r
  while (l <= r) {
    const mid = l + Math.floor((r - l) / 2)
    if (canRepair(mid)) {
      ans = mid
      r = mid - 1
    } else {
      l = mid + 1
    }
  }

  return ans
}
