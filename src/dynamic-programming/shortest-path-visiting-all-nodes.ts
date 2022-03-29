function shortestPathLength(graph: number[][]): number {
  const queue: [vertex: number, state: number, dist: number][] = []
  const n = graph.length
  const seen: boolean[][] = Array.from({ length: n }, () => [])
  const targetState = (1 << n) - 1
  for (let i = 0; i < n; ++i) {
    queue.push([i, 1 << i, 0])
    seen[i][1 << i] = true
  }

  while (queue.length) {
    const [vertex, state, dist] = queue.shift()!

    if (state === targetState) {
      return dist
    }

    for (const neighbor of graph[vertex]) {
      const nextState = (1 << neighbor) | state
      if (seen[neighbor][nextState] === true) continue

      seen[neighbor][nextState] = true
      queue.push([neighbor, nextState, dist + 1])
    }
  }

  return -1
}

export function shortestPathLength1(graph: number[][]): number {
  const dist: number[][] = []
  const n = graph.length

  for (let i = 0; i < n; ++i) {
    dist[i] = Array.from<number>({ length: n }).fill(Infinity)
    dist[i][i] = 0
    for (const j of graph[i]) {
      dist[i][j] = 1
    }
  }
  for (let k = 0; k < n; ++k) {
    for (let i = 0; i < n; ++i) {
      for (let j = 0; j < n; ++j) {
        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j])
      }
    }
  }

  //dp[i][j]表示当前最后一个遍历到的节点为i,且所有节点的访问情况为j是，所走过路径的总和
  const dp: number[][] = []

  for (let i = 0; i < n; ++i) {
    dp[i] = Array.from<number>({ length: 1 << n }).fill(Infinity)
  }

  for (let mask = 1; mask < 1 << n; ++mask) {
    if ((mask & (mask - 1)) === 0) {
      dp[31 - Math.clz32(mask)][mask] = 0
    } else {
      for (let u = 0; u < n; ++u) {
        if (mask & (u << 1)) {
          for (let v = 0; v < n; ++v) {
            if (mask & (1 << v)) {
              dp[u][mask] = Math.min(
                dp[u][mask],
                dp[v][mask ^ (1 << u)] + dist[v][u]
              )
            }
          }
        }
      }
    }
  }

  let ans = dp[0][(1 << n) - 1]

  for (let i = 1; i < n; ++i) {
    ans = Math.min(ans, dp[i][(1 << n) - 1])
  }

  return ans
}
