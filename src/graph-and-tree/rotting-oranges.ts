const dirs = [
  [-1, 0],
  [0, 1],
  [1, 0],
  [0, -1],
]

function orangesRotting(grid: number[][]): number {
  let queue: number[][] = []

  let total = 0
  let rot = 0
  const n = grid.length
  const m = grid[0].length
  let depth = 0

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (grid[i][j] === 1) {
        total++
      } else if (grid[i][j] === 2) {
        total++
        rot++
        queue.push([i, j])
      }
    }
  }

  if (total === rot) {
    return 0
  }

  while (queue.length) {
    const nextQueue = []
    depth++
    for (const [x, y] of queue) {
      for (const dir of dirs) {
        const newX = x + dir[0]
        const newY = y + dir[1]

        if (
          newX < 0 ||
          newX >= n ||
          newY < 0 ||
          newY >= m ||
          grid[newX][newY] === 2 ||
          grid[newX][newY] === 0
        ) {
          continue
        }
        rot++
        nextQueue.push([newX, newY])
        grid[newX][newY] = 2
        if (rot === total) {
          return depth
        }
      }
    }

    queue = nextQueue
  }
  return -1
}
