function eliminateMaximum(dist: number[], speed: number[]): number {
  const arrivalTimes: number[] = []
  const n = dist.length

  for (let i = 0; i < n; i++) {
    arrivalTimes[i] = Math.ceil(dist[i] / speed[i])
  }

  arrivalTimes.sort((a, b) => a - b)

  for (let i = 0; i < n; i++) {
    if (arrivalTimes[i] <= i) {
      return i
    }
  }

  return n
}
