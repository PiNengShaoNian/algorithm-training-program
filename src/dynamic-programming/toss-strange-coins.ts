// 1230. 抛掷硬币
// 有一些不规则的硬币。在这些硬币中，prob[i] 表示第 i 枚硬币正面朝上的概率。

// 请对每一枚硬币抛掷 一次，然后返回正面朝上的硬币数等于 target 的概率。

// 示例 1：

// 输入：prob = [0.4], target = 1
// 输出：0.40000
// 示例 2：

// 输入：prob = [0.5,0.5,0.5,0.5,0.5], target = 0
// 输出：0.03125

// 提示：

// 1 <= prob.length <= 1000
// 0 <= prob[i] <= 1
// 0 <= target <= prob.length
// 如果答案与标准答案的误差在 10^-5 内，则被视为正确答案。

export function probabilityOfHeads(prob: number[], target: number): number {
  //dp[i][j]为把前i枚硬币都抛了，其中有j枚硬币朝上的概率,其中i,j都从1开始
  const n = prob.length
  const m = target
  const dp: number[][] = Array.from({ length: n + 1 }, () =>
    Array.from<number>({ length: m + 1 }).fill(0)
  )

  //一枚硬币都还没抛，但是却又有硬币朝上的概率为0
  for (let i = 0; i <= m; ++i) {
    dp[0][i] = 0
  }

  dp[0][0] = 1
  let p = 1
  for (let i = 1; i <= n; ++i) {
    p *= 1 - prob[i - 1]
    dp[i][0] = p
  }

  for (let i = 1; i <= n; ++i) {
    for (let j = 1; j <= i && j <= m; ++j) {
      //如果前i-1枚硬币中刚好有j-1朝上那么就得乘第i枚朝上的概率
      //如果前i-1枚硬币中已经有j枚硬币朝上那么就得乘第i枚朝下的概率
      //dp[i][j]就是这两种情况的和
      dp[i][j] =
        dp[i - 1][j - 1] * prob[i - 1] + dp[i - 1][j] * (1 - prob[i - 1])
    }
  }

  return dp[n][m]
}
