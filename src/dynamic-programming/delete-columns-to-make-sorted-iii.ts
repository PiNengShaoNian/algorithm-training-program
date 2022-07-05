//LIS模板题
export function minDeletionSize(strs: string[]): number {
  const dp: number[] = []
  const n = strs[0].length
  const m = strs.length

  /**
   * 对于数组strs:
   * ["babca",
   *  "bbazb"]
   * 可以把strs[0][0],strs[1][0]看作一个整体
   *     把strs[0][1],strs[1][1]看作一个整体
   *     把strs[0][2],strs[1][2]看作一个整体
   * 然后再去比较他们之间的大小，这样就把问题转换成已维的LIS问题
   * 答案就是单个字符串长度减掉最长的LIS长度
   */
  dp[0] = 1
  let LIS = 1

  for (let i = 1; i < n; ++i) {
    dp[i] = 1
    for (let j = 0; j < i; ++j) {
      let less = true
      //对该列元素和前面的每一列比较大小
      for (let k = 0; k < m; ++k) {
        if (strs[k][j] > strs[k][i]) {
          less = false
          break
        }
      }

      if (less) {
        dp[i] = Math.max(dp[i], dp[j] + 1)
      }
    }

    LIS = Math.max(LIS, dp[i])
  }

  return n - LIS
}
