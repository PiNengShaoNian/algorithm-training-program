export function numberOfPatterns(m: number, n: number): number {
  // 1   2   3
  // 4   5   6
  // 7   8   9

  //skip[i][j]表示从i点到j点中间经过了的那个点，比如skip[1][3] = 2,因为从1点到3点中间经过了2点
  const skip: number[][] = []

  for (let i = 0; i < 10; ++i) {
    skip[i] = Array.from<number>({ length: 10 }).fill(0)
  }

  skip[1][3] = skip[3][1] = 2
  skip[1][7] = skip[7][1] = 4
  skip[1][9] = skip[9][1] = 5
  skip[2][8] = skip[8][2] = 5
  skip[3][7] = skip[7][3] = 5
  skip[3][9] = skip[9][3] = 6
  skip[4][6] = skip[6][4] = 5
  skip[7][9] = skip[9][7] = 8

  const visited: boolean[] = []
  const Impl = (current: number, remainingCount: number): number => {
    if (remainingCount === 0) return 1

    visited[current] = true
    let result = 0
    for (let i = 1; i <= 9; ++i) {
      const crossThroughNumber = skip[current][i]

      //判断下一个点是否合法
      //(1)它还没有被使用
      //(2)从current到它中间没有经过其他点
      //(3)如果(2)不能满足则要保证中间经过的点已经被使用过了
      if (
        !visited[i] &&
        (crossThroughNumber === 0 || visited[crossThroughNumber])
      ) {
        result += Impl(i, remainingCount - 1)
      }
    }

    visited[current] = false

    return result
  }

  let ans = 0
  for (let i = m; i <= n; ++i) {
    //点1,3,7,9都是对称的只用算出1的结果乘4就行
    //由于第一个点已经被当作起点使用了所以当前还剩下的点的数量应该为i-1
    ans += 4 * Impl(1, i - 1)
    //同理2,4,6,8也是对称的
    ans += 4 * Impl(2, i - 1)
    //点5需要单独计算
    ans += Impl(5, i - 1)
  }

  return ans
}
