export function fullBloomFlowers(
  flowers: number[][],
  people: number[]
): number[] {
  const timeToIncr: Record<number, number> = {}

  for (const f of flowers) {
    const [start, end] = f
    timeToIncr[start] = (timeToIncr[start] ?? 0) + 1
    timeToIncr[end + 1] = (timeToIncr[end + 1] ?? 0) - 1
  }

  const events = Object.entries(timeToIncr)
    .map((v) => [Number(v[0]), Number(v[1])])
    .sort((a, b) => {
      return a[0] - b[0]
    })

  const indices = Array.from({ length: people.length }, (_, i) => i)
  indices.sort((a, b) => people[a] - people[b])

  let curr = 0
  let idx = 0
  const eventLen = events.length
  const ans: number[] = []
  for (const p of indices) {
    while (idx < eventLen && events[idx][0] <= people[p]) {
      curr += events[idx][1]
      idx++
    }

    ans[p] = curr
  }

  return ans
}
