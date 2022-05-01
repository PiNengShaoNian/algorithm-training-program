export function maxStudents(seats: string[][]): number {
  const used = Array.from({ length: 64 }).fill(false)
  let avalSets = 0
  const n = seats.length
  const m = seats[0].length

  for (let i = 0; i < n; ++i) {
    for (let j = 0; j < m; ++j) {
      if (seats[i][j] === '.') {
        ++avalSets
      }
    }
  }

  const canMeet = (students: number, remainingSeats: number): boolean => {
    if (students === 0) {
      return true
    }

    for (let i = 0; i < n; ++i) {
      for (let j = 0; j < m; ++j) {
        if (
          seats[i][j] === '.' &&
          !used[i * m + j] &&
          !used[(i - 1) * m + j - 1] &&
          !used[(i - 1) * m + j + 1] &&
          !used[i * m + j - 1] &&
          !used[i * m + j + 1]
        ) {
          let usedCount = 1
          used[i * m + j] = true
          if (i - 1 >= 0) {
            if (seats[i - 1][j - 1] === '.') {
              const index = (i - 1) * m + j - 1
              if (!used[index]) {
                used[index] = true
                ++usedCount
              }
            }

            if (seats[i - 1][j + 1] === '.') {
              const index = (i - 1) * m + j + 1
              if (!used[index]) {
                used[index] = true
                ++usedCount
              }
            }
          }

          if (seats[i][j - 1] === '.') {
            const index = i * m + j - 1
            if (!used[index]) {
              used[index] = true
              ++usedCount
            }
          }

          if (seats[i][j + 1] === '.') {
            const index = i * m + j + 1
            if (!used[index]) {
              used[index] = true
              ++usedCount
            }
          }

          if (remainingSeats - usedCount < students - 1) {
            used[i * m + j] = false
            if (i - 1 >= 0) {
              if (seats[i - 1][j - 1] === '.') {
                used[(i - 1) * m + j - 1] = false
              }

              if (seats[i - 1][j + 1] === '.') {
                used[(i - 1) * m + j + 1] = false
              }
            }

            if (seats[i][j - 1] === '.') {
              used[i * m + j - 1] = false
            }

            if (seats[i][j + 1] === '.') {
              used[i * m + j + 1] = false
            }

            return false
          }

          if (canMeet(students - 1, remainingSeats - usedCount)) return true

          used[i * m + j] = false
          if (i - 1 >= 0) {
            if (seats[i - 1][j - 1] === '.') {
              used[(i - 1) * m + j - 1] = false
            }

            if (seats[i - 1][j + 1] === '.') {
              used[(i - 1) * m + j + 1] = false
            }
          }

          if (seats[i][j - 1] === '.') {
            used[i * m + j - 1] = false
          }

          if (seats[i][j + 1] === '.') {
            used[i * m + j + 1] = false
          }
        }
      }
    }

    return false
  }

  let l = 0
  let r = avalSets
  let ans = 0

  while (l <= r) {
    const mid = (l + r) >> 1
    used.fill(false)
    if (canMeet(mid, avalSets)) {
      ans = mid
      l = mid + 1
    } else {
      r = mid - 1
    }
  }
  return ans
}
