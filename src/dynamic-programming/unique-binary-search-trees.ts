export function numTrees(n: number): number {
  const G: number[] = Array.from<number>({ length: n + 1 }).fill(0)

  //G[n]表示一个长度为n的序列能构成的二叉搜索树的数量
  G[0] = G[1] = 1

  //枚举不同长度的序列
  for (let nc = 2; nc <= n; ++nc) {
    //枚举不同的根节点
    for (let root = 1; root <= nc; ++root) {
      /*
        dp[i] = i个不同的数组成的二叉搜索数的个数
        假设 i = 5
        当根节点等于 1 时 ，其余数字都比1大，只能在右边 dp[i] += dp[4]
        当根节点等于 2 时，左边有一个1比2小，右边有三个比2大的数字 dp[i] += dp[1] * dp[3]
        当根节点等于 3 时，左边有两个数比3小，右边有两个数比3大的数字 dp[i] += dp[2] * dp[2]
        ...
        知道根节点等于5，左边有4个数字比5小，只能放在5的左边,dp[i] += dp[4]
         */
      G[nc] += G[root - 1] * G[nc - root]
    }
  }

  return G[n]
}
