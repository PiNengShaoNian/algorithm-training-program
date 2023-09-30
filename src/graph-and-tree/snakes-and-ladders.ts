const id2rc = (id: number, n: number): [number, number] => {
  let r: number = Math.floor((id - 1) / n) // 算出他的行偏移量
  let c = (id - 1) % n // 算出他的列偏移量
  if (r % 2 == 1) {
    c = n - 1 - c // 当行号为偶数是他的列从0开始，奇数时从n - 1开始
  }
  return [n - 1 - r, c]
}

function snakesAndLadders(board: number[][]): number {
  const visited = new Set()
  let queue = [1]
  let depth = 0
  const n = board.length
  visited.add(1)
  while (queue.length) {
    depth++
    const nextQueue = []
    let idx = 0
    const len = queue.length
    while (idx < len) {
      const cur = queue[idx++]
      for (let i = 1; i <= 6; i++) {
        if (cur + i > n * n) {
          break
        }

        let next = cur + i
        const [x, y] = id2rc(next, n)
        if (board[x][y] !== -1) {
          next = board[x][y]
        }

        if (next === n * n) {
          return depth
        }

        if (!visited.has(next)) {
          visited.add(next)
          nextQueue.push(next)
        }
      }
    }

    queue = nextQueue
  }

  return -1
}
