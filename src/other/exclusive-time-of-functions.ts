export function exclusiveTime(n: number, logs: string[]): number[] {
  const ans = Array.from<number>({ length: n }).fill(0)
  const stack: number[][] = [] // [id, startTime]

  for (const log of logs) {
    const [id, type, time] = log.split(':')
    if (type === 'start') {
      if (stack.length) {
        ans[stack[stack.length - 1][0]] +=
          Number(time) - stack[stack.length - 1][1]
        stack[stack.length - 1][1] = Number(time)
      }
      stack.push([Number(id), Number(time)])
    } else {
      const t = stack.pop()!
      ans[t[0]] += Number(time) - t[1] + 1
      if (stack.length) {
        stack[stack.length - 1][1] = Number(time) + 1
      }
    }
  }

  return ans
}
