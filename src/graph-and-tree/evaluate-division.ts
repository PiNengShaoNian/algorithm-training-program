class UnionFind {
  private parent: number[]
  private weight: number[]

  constructor(n: number) {
    const parent = []
    for (let i = 0; i < n; i++) {
      parent[i] = i
    }
    this.parent = parent
    this.weight = Array.from<number>({ length: n }).fill(1)
  }

  union(x: number, y: number, value: number): void {
    const rootX = this.find(x)
    const rootY = this.find(y)

    if (rootX === rootY) {
      return
    }

    this.parent[rootX] = rootY
    // value * weight[y] = weight[rootX] * weight[x]
    this.weight[rootX] = (value * this.weight[y]) / this.weight[x]
  }

  find(x: number): number {
    if (x !== this.parent[x]) {
      const origin = this.parent[x]
      this.parent[x] = this.find(this.parent[x])
      this.weight[x] *= this.weight[origin]
    }

    return this.parent[x]
  }

  isConnected(x: number, y: number): number {
    const rootX = this.find(x)
    const rootY = this.find(y)

    if (rootX === rootY) {
      return this.weight[x] / this.weight[y]
    } else {
      return -1
    }
  }
}

function calcEquation(
  equations: string[][],
  values: number[],
  queries: string[][]
): number[] {
  const equationSize = equations.length
  const uf = new UnionFind(2 * equationSize)
  let nameToId = new Map<string, number>()
  let id = 0
  for (let i = 0; i < equationSize; i++) {
    const [a, b] = equations[i]

    if (!nameToId.has(a)) {
      nameToId.set(a, id++)
    }

    if (!nameToId.has(b)) {
      nameToId.set(b, id++)
    }

    uf.union(nameToId.get(a)!, nameToId.get(b)!, values[i])
  }

  const querySize = queries.length
  const ans: number[] = []
  for (let i = 0; i < querySize; i++) {
    const [a, b] = queries[i]
    let id1 = nameToId.get(a) ?? null
    let id2 = nameToId.get(b) ?? null

    if (id1 === null || id2 === null) {
      ans.push(-1)
    } else {
      ans.push(uf.isConnected(id1, id2))
    }
  }

  return ans
}
