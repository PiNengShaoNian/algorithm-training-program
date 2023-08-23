function leastInterval(tasks: string[], n: number): number {
  const freq: Record<string, number> = {}
  for (const task of tasks) {
    freq[task] = (freq[task] ?? 0) + 1
  }

  const rest: number[] = []
  const nextValid: number[] = []

  for (const [_, v] of Object.entries(freq)) {
    rest.push(v)
    nextValid.push(1)
  }
  const taskCnt = tasks.length
  let time = 0
  const taskCategoryCnt = Object.keys(freq).length

  for (let i = 0; i < taskCnt; i++) {
    ++time
    let minNextValid = Infinity
    for (let j = 0; j < taskCategoryCnt; j++) {
      if (rest[j]) {
        minNextValid = Math.min(minNextValid, nextValid[j])
      }
    }

    time = Math.max(time, minNextValid)
    let best = -1
    for (let j = 0; j < taskCategoryCnt; j++) {
      if (rest[j] && nextValid[j] <= time) {
        if (best === -1 || rest[best] < rest[j]) {
          best = j
        }
      }
    }
    rest[best]--
    nextValid[best] = time + n + 1
  }

  return time
}
