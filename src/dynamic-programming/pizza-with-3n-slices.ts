import { PriorityQueue } from '../utils/PriorityQueue'

const core = (nums: number[]): number => {
  const n = Math.floor((nums.length + 1) / 3)
  //dp[i][j]代表在前i个数中选取了j个不相邻的数能构成的最大和
  const dp: number[][] = []

  for (let i = 0; i <= nums.length; ++i) {
    dp[i] = []
    dp[i][0] = 0
  }

  for (let i = 0; i <= n; ++i) {
    dp[0][i] = 0
  }

  for (let i = 1; i <= nums.length; ++i) {
    for (let j = 1; j <= n; ++j) {
      dp[i][j] = Math.max(
        //选了第i个数,之前的数字就只能在[0,i- 2]区间内选择
        (i - 2 >= 0 ? dp[i - 2][j - 1] : 0) + nums[i - 1],
        //不选第i个数
        dp[i - 1][j]
      )
    }
  }

  return dp[nums.length][n]
}

//菜的抠脚压根看不懂证明，只知道是问题等价于求一个从3n长的循环数组中
//挑选n个互不相邻的数能构成的最大和
export function maxSizeSlices(slices: number[]): number {
  return Math.max(
    core(slices.slice(1)),
    core(slices.slice(0, slices.length - 1))
  )
}

type Node = {
  l: number
  r: number
  v: number
}

//双向链表贪心解法
export function maxSizeSlices1(slices: number[]): number {
  const list: Node[] = []
  const k = slices.length / 3
  const n = slices.length
  class Id {
    constructor(public id: number) {}

    compareTo(that: Id) {
      return list[that.id].v - list[this.id].v
    }
  }
  const del = (i: number) => {
    list[list[i].r].l = list[i].l
    list[list[i].l].r = list[i].r
  }
  const pq = new PriorityQueue<Id>()
  const candTake: boolean[] = []
  for (let i = 0; i < n; ++i) {
    list[i] = {
      l: (i - 1 + n) % n,
      r: (i + 1) % n,
      v: slices[i],
    }

    candTake[i] = true
  }

  for (let i = 0; i < n; ++i) {
    pq.push(new Id(i))
  }

  let count = 0
  let ans = 0
  while (count < k) {
    const id = pq.pop()!.id

    if (candTake[id]) {
      ans += list[id].v
      ++count

      const pre = list[id].l
      const next = list[id].r
      list[id].v = list[pre].v + list[next].v - list[id].v
      candTake[pre] = candTake[next] = false
      pq.push(new Id(id))
      del(pre)
      del(next)
    }
  }

  return ans
}
