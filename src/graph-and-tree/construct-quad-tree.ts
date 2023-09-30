class Node {
  val: boolean
  isLeaf: boolean
  topLeft: Node | null
  topRight: Node | null
  bottomLeft: Node | null
  bottomRight: Node | null
  constructor(
    val?: boolean,
    isLeaf?: boolean,
    topLeft?: Node,
    topRight?: Node,
    bottomLeft?: Node,
    bottomRight?: Node
  ) {
    this.val = val === undefined ? false : val
    this.isLeaf = isLeaf === undefined ? false : isLeaf
    this.topLeft = topLeft === undefined ? null : topLeft
    this.topRight = topRight === undefined ? null : topRight
    this.bottomLeft = bottomLeft === undefined ? null : bottomLeft
    this.bottomRight = bottomRight === undefined ? null : bottomRight
  }
}

export function construct(grid: number[][]): Node | null {
  const n = grid.length
  if (n === 1) {
    return new Node(grid[0][0] ? true : false, true)
  }

  const build = (row: number, col: number, n: number) => {
    const val = grid[row][col]
    let equals = true
    mainLoop: for (let i = row; i < row + n; i++) {
      for (let j = col; j < col + n; j++) {
        if (grid[i][j] !== val) {
          equals = false
          break mainLoop
        }
      }
    }

    if (equals) {
      return new Node(val ? true : false, true)
    }

    const node = new Node(true, false)
    node.topLeft = build(row, col, n / 2)
    node.topRight = build(row, col + n / 2, n / 2)
    node.bottomLeft = build(row + n / 2, col, n / 2)
    node.bottomRight = build(row + n / 2, col + n / 2, n / 2)

    return node
  }

  return build(0, 0, n)
}
