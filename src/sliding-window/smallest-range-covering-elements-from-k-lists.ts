import { PriorityQueue } from '../utils/PriorityQueue'

export function smallestRange(nums: number[][]): number[] {
  let leftRange = 0
  let rightRange = Infinity
  let max = -Infinity
  let minRange = Infinity
  const n = nums.length
  const next = Array.from<number>({ length: n }).fill(0)

  const pq = new PriorityQueue<number>((index1, index2) => {
    const a = nums[index1][next[index1]]
    const b = nums[index2][next[index2]]

    if (a < b) return true
    else return false
  })

  for (let i = 0; i < n; ++i) {
    pq.push(i)
    max = Math.max(max, nums[i][0])
  }

  while (true) {
    const minIndex = pq.pop()!
    const curRange = max - nums[minIndex][next[minIndex]]

    if (curRange < minRange) {
      minRange = curRange
      rightRange = max
      leftRange = nums[minIndex][next[minIndex]]
    }

    ++next[minIndex]

    if (next[minIndex] === nums[minIndex].length) break

    pq.push(minIndex)
    max = Math.max(nums[minIndex][next[minIndex]], max)
  }

  return [leftRange, rightRange]
}

export function smallestRange1(nums: number[][]): number[] {
  const valToIndices = new Map<number, number[]>()
  const n = nums.length
  let min = Infinity
  let max = -Infinity
  for (let i = 0; i < n; ++i) {
    for (let x of nums[i]) {
      const list = valToIndices.get(x) ?? []
      valToIndices.set(x, list)
      list.push(i)
      min = Math.min(min, x)
      max = Math.max(max, x)
    }
  }

  let l = min
  let r = min - 1
  let inside = 0
  const fre: Record<number, number> = {}
  let bestLeft = 0
  let bestRight = Infinity

  while (l <= max) {
    while (inside < n) {
      ++r
      if (r > max) return [bestLeft, bestRight]
      if (!valToIndices.has(r)) continue

      for (const index of valToIndices.get(r)!) {
        fre[index] = (fre[index] ?? 0) + 1

        if (fre[index] === 1) {
          ++inside
        }
      }
    }

    if (inside === n && r - l < bestRight - bestLeft) {
      bestLeft = l
      bestRight = r
    }

    if (valToIndices.has(l)) {
      for (const index of valToIndices.get(l)!) {
        --fre[index]

        if (fre[index] === 0) {
          --inside
        }
      }
    }

    ++l
  }

  return [bestLeft, bestRight]
}
