export function lastStoneWeightII(stones: number[]): number {
  //可以将该问题转换为零一背包问题解题
  //原问题等价于用一个所有石子和一半的背包来装这些石子，此时装进背包的石子和
  //背包外石子的重量差是最小的，这个差也就是我们所要求的答案

  let sum = 0
  const n = stones.length
  for (let i = 0; i < n; ++i) {
    sum += stones[i]
  }

  const max = sum >> 1
  //dp[i]表示一个能装i重量的背包在stones中选石头能装进的最大重量
  const dp: number[] = Array.from<number>({ length: max + 1 }).fill(0)
  for (let i = 0; i < n; ++i) {
    const stone = stones[i]
    for (let j = max; j >= stone; --j) {
      dp[j] = Math.max(dp[j], dp[j - stone] + stone)
    }
  }

  return sum - dp[max] * 2
}
