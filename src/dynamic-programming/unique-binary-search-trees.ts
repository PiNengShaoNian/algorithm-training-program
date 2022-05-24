export function numTrees(n: number): number {
  const G: number[] = Array.from<number>({ length: n + 1 }).fill(0)

  //G[n]表示一个长度为n的序列能构成的二叉搜索树的数量
  G[0] = G[1] = 1

  //枚举不同长度的序列
  for (let nc = 2; nc <= n; ++nc) {
    //枚举不同的根节点
    for (let root = 1; root <= nc; ++root) {
      G[nc] += G[root - 1] * G[nc - root]
    }
  }

  return G[n]
}
