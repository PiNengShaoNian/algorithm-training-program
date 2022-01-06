//BFS解法
export function numSquares(n: number): number {
  const queue: [remain: number, dis: number][] = []
  const visited = new Set<number>()
  queue.push([n, 0])
  visited.add(n)

  while (queue.length) {
    const [cur, dis] = queue.shift()!

    for (let i = 1; i * i <= cur; ++i) {
      const remain = cur - i * i

      if (remain === 0) {
        return dis + 1
      }

      if (!visited.has(remain)) {
        queue.push([remain, dis + 1])
        visited.add(remain)
      }
    }
  }

  return -1
}

//双向BFS
export function numSquares1(n: number): number {
  let queueBegin: number[] = []
  let queueEnd: number[] = []
  const distBegin = new Map<number, number>()
  const distEnd = new Map<number, number>()

  queueBegin.push(n)
  distBegin.set(n, 0)
  queueEnd.push(0)
  distEnd.set(0, 0)

  const expand = (
    queue: number[],
    distTo: Map<number, number>,
    otherDistTo: Map<number, number>
  ): number => {
    const nextQueue: number[] = []
    while (queue.length) {
      const cur = queue.shift()!
      const dis = distTo.get(cur)!

      //从n向零拓展
      if (queue === queueBegin) {
        for (let i = 1; i * i <= cur; ++i) {
          const next = cur - i * i
          if (otherDistTo.has(next)) {
            return otherDistTo.get(next)! + dis + 1
          }

          if (distTo.has(next)) continue
          nextQueue.push(next)
          distTo.set(next, dis + 1)
        }
      }
      //从0向n拓展
      else {
        for (let i = 1; i * i + cur <= n; ++i) {
          const next = i * i + cur
          if (otherDistTo.has(next)) {
            return otherDistTo.get(next)! + dis + 1
          }

          if (distTo.has(next)) continue

          nextQueue.push(next)
          distTo.set(next, dis + 1)
        }
      }
    }

    queue === queueBegin ? (queueBegin = nextQueue) : (queueEnd = nextQueue)
    return -1
  }

  while (queueBegin.length || queueEnd.length) {
    let res = expand(queueBegin, distBegin, distEnd)

    if (res !== -1) return res

    res = expand(queueEnd, distEnd, distBegin)

    if (res !== -1) return res
  }

  return -1
}
