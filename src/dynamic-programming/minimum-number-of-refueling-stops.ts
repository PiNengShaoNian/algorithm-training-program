import { PriorityQueue } from '../utils/PriorityQueue'

export function minRefuelStops(
  target: number,
  startFuel: number,
  stations: number[][]
): number {
  //用贪心的思路来做，在油够的情况下，一路不加油一直往前走，
  //在此过程中也不断的把每个加油站的油放在最大优先队列中
  //等到油不够的时候再从优先队列了把数量最大的油取出
  //在把加油次数加一
  let tank = startFuel
  let res = 0
  //将[target,0]设置为一个虚拟加油站，如果能走到这个虚拟加油站说明有解
  //如果遍历不到这个加油站说明车开到途中就会没油就会返回-1
  stations.push([target, 0])
  const maxPQ = new PriorityQueue<number>((a, b) => a > b)
  let curPosition = 0

  for (let i = 0; i < stations.length; ++i) {
    const [stationPosition, fuel] = stations[i]
    const dist = stationPosition - curPosition
    while (tank - dist < 0) {
      if (maxPQ.isEmpty()) return -1

      //每次都取出收集的最大的油，这样就能保证加油次数最少
      tank += maxPQ.pop()!
      ++res
    }

    tank -= dist
    curPosition = stationPosition
    //行驶到了该加油站，但是不缺油，把该加油站的油收集起来，后面可能会用到
    maxPQ.push(fuel)
  }

  return res
}

//动态规划解法
export function minRefuelStops1(
  target: number,
  startFuel: number,
  stations: number[][]
): number {
  const n = stations.length
  //dp[i]表示加i次油能到达的最远距离为dp[i]
  const dp: number[] = Array.from<number>({ length: n + 1 }).fill(0)
  //加零次油能到startFuel距离
  dp[0] = startFuel

  for (let i = 0; i < n; ++i) {
    for (let t = i; t >= 0; --t) {
      //如果加t次油能到达stations[i],则更新dp[t + 1]的答案
      if (dp[t] >= stations[i][0]) {
        dp[t + 1] = Math.max(dp[t + 1], dp[t] + stations[i][1])
      }
    }
  }

  for (let i = 0; i <= n; ++i) {
    if (dp[i] >= target) return i
  }

  return -1
}
