// 265. 粉刷房子 II
// 假如有一排房子，共 n 个，每个房子可以被粉刷成 k 种颜色中的一种，你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。

// 当然，因为市场上不同颜色油漆的价格不同，所以房子粉刷成不同颜色的花费成本也是不同的。每个房子粉刷成不同颜色的花费是以一个 n x k 的矩阵来表示的。

// 例如，costs[0][0] 表示第 0 号房子粉刷成 0 号颜色的成本花费；costs[1][2] 表示第 1 号房子粉刷成 2 号颜色的成本花费，以此类推。请你计算出粉刷完所有房子最少的花费成本。

// 注意：

// 所有花费均为正整数。

// 示例：

// 输入: [[1,5,3],[2,9,4]]
// 输出: 5
// 解释: 将 0 号房子粉刷成 0 号颜色，1 号房子粉刷成 2 号颜色。最少花费: 1 + 4 = 5;
//      或者将 0 号房子粉刷成 2 号颜色，1 号房子粉刷成 0 号颜色。最少花费: 3 + 2 = 5.
// 进阶：
// 您能否在 O(nk) 的时间复杂度下解决此问题？

export function minCostII(costs: number[][]): number {
  const dp: number[][] = []
  const n = costs.length
  const m = costs[0].length

  for (let i = 0; i < n; ++i) {
    dp[i] = []
  }

  for (let i = 0; i < m; ++i) {
    dp[0][i] = costs[0][i]
  }

  for (let i = 1; i < n; ++i) {
    for (let j = 0; j < m; ++j) {
      let min = Infinity
      for (let k = 0; k < m; ++k) {
        if (k !== j) {
          min = Math.min(dp[i - 1][k], min)
        }
      }

      dp[i][j] = min + costs[i][j]
    }
  }

  let ans = Infinity

  for (let i = 0; i < m; ++i) {
    ans = Math.min(dp[n - 1][i], ans)
  }

  return ans
}

//保存i-1中次小和最小的状态能省去一轮循环
export function minCostII1(costs: number[][]): number {
  const dp: number[][] = []
  const n = costs.length
  const m = costs[0].length

  for (let i = 0; i < n; ++i) {
    dp[i] = []
  }

  //最小
  let c1 = 0
  //次小
  let c2 = 0
  let temp1 = Infinity
  let temp2 = Infinity
  for (let i = 0; i < m; ++i) {
    dp[0][i] = costs[0][i]

    if (dp[0][i] < temp1) {
      temp2 = temp1
      temp1 = dp[0][i]
    } else if (dp[0][i] < temp2) {
      temp2 = dp[0][i]
    }
  }

  c1 = temp1
  c2 = temp2

  for (let i = 1; i < n; ++i) {
    temp1 = Infinity
    temp2 = Infinity
    for (let j = 0; j < m; ++j) {
      if (dp[i - 1][j] !== c1) dp[i][j] = c1 + costs[i][j]
      else dp[i][j] = c2 + costs[i][j]

      if (dp[i][j] < temp1) {
        temp2 = temp1
        temp1 = dp[i][j]
      } else if (dp[i][j] < temp2) {
        temp2 = dp[i][j]
      }
    }
    c1 = temp1
    c2 = temp2
  }

  let ans = Infinity

  for (let i = 0; i < m; ++i) {
    ans = Math.min(dp[n - 1][i], ans)
  }

  return ans
}
