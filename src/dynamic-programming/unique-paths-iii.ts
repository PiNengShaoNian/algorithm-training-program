function uniquePathsIII(grid: number[][]): number {
  let visited = 0
  const rows = grid.length
  const cols = grid[0].length

  let startRow: number, startCol: number
  let targetState = 0
  for (let i = 0; i < rows; ++i) {
    for (let j = 0; j < cols; ++j) {
      if (grid[i][j] === 1) {
        startRow = i
        startCol = j
      }

      if (grid[i][j] !== -1) {
        targetState |= 1 << (i * cols + j)
      }
    }
  }

  const Impl = (row: number, col: number): number => {
    const current = 1 << (row * cols + col)
    visited |= current
    if (grid[row][col] === 2) {
      if (visited === targetState) {
        visited = visited & ~current
        return 1
      } else {
        visited = visited & ~current
        return 0
      }
    }

    let ans = 0
    if (
      row + 1 < rows &&
      grid[row + 1][col] !== -1 &&
      (visited & (1 << ((row + 1) * cols + col))) === 0
    ) {
      ans += Impl(row + 1, col)
    }

    if (
      row - 1 >= 0 &&
      grid[row - 1][col] !== -1 &&
      (visited & (1 << ((row - 1) * cols + col))) === 0
    ) {
      ans += Impl(row - 1, col)
    }

    if (
      col + 1 < cols &&
      grid[row][col + 1] !== -1 &&
      (visited & (1 << (row * cols + col + 1))) === 0
    ) {
      ans += Impl(row, col + 1)
    }

    if (
      col - 1 >= 0 &&
      grid[row][col - 1] !== -1 &&
      (visited & (1 << (row * cols + col - 1))) === 0
    ) {
      ans += Impl(row, col - 1)
    }

    visited = visited & ~current

    return ans
  }

  return Impl(startRow!, startCol!)
}
