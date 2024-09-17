function numBusesToDestination(
  routes: number[][],
  source: number,
  target: number
): number {
  if (source == target) {
    return 0
  }

  const n = routes.length
  const edge: boolean[][] = Array.from({ length: n }, () =>
    Array(n).fill(false)
  )
  const siteToBuses = new Map<number, number[]>()
  for (let i = 0; i < n; i++) {
    for (const site of routes[i]) {
      if (!siteToBuses.has(site)) {
        siteToBuses.set(site, [])
      }
      for (const j of siteToBuses.get(site)!) {
        edge[i][j] = edge[j][i] = true
      }
      siteToBuses.get(site)!.push(i)
    }
  }

  const dis: number[] = Array(n).fill(-1)
  const queue: number[] = []
  for (const bus of siteToBuses.get(source) ?? []) {
    dis[bus] = 1
    queue.push(bus)
  }

  while (queue.length > 0) {
    const x = queue.shift()!
    for (let y = 0; y < n; y++) {
      if (edge[x][y] && dis[y] === -1) {
        dis[y] = dis[x] + 1
        queue.push(y)
      }
    }
  }

  let ret = Number.MAX_SAFE_INTEGER
  for (const bus of siteToBuses.get(target) ?? []) {
    if (dis[bus] !== -1) {
      ret = Math.min(ret, dis[bus])
    }
  }

  return ret === Number.MAX_SAFE_INTEGER ? -1 : ret
}
