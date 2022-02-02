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
