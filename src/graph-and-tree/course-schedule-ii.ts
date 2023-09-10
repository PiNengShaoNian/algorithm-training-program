export function findOrder(
  numCourses: number,
  prerequisites: number[][]
): number[] {
  let ans: number[] = []

  const graph: number[][] = []
  const indegree: number[] = []
  for (let i = 0; i < numCourses; i++) {
    graph[i] = []
    indegree[i] = 0
  }

  const len = prerequisites.length

  for (let i = 0; i < len; i++) {
    const [to, from] = prerequisites[i]

    graph[from].push(to)
    indegree[to]++
  }

  const queue: number[] = []

  for (let i = 0; i < numCourses; i++) {
    if (indegree[i] === 0) {
      queue.push(i)
    }
  }

  while (queue.length) {
    const vertex = queue.pop()!
    ans.push(vertex)
    for (const neighbor of graph[vertex]) {
      if (--indegree[neighbor] === 0) {
        queue.push(neighbor)
      }
    }
  }

  return ans.length === numCourses ? ans : []
}
