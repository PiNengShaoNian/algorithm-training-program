import { TreeMap } from '../utils/TreeMap'

export function maxSumSubmatrix(matrix: number[][], k: number): number {
  const rows = matrix.length
  const cols = matrix[0].length
  let ans = -Infinity

  //通过枚举矩阵上下行，然后通过累加每列的累加值可以将子矩阵和用
  //一维前缀和表示出来，这时候就能将问题简化到一维
  //这时候的问题就变为求满足presumRight - presumLeft <= k
  //不等式中(presumRight - presumLeft)的最大值,对不等式
  //做一下变换得到 presumRight - k <= presumLeft
  //结合两个不等式可以看出要求presumRight - presumLeft的最大值
  //则需要寻找最小的满足 presumRight - k <= presumLeft的presumLeft
  for (let i = 0; i < rows; ++i) {
    const arr: number[] = Array.from<number>({ length: cols }).fill(0)
    for (let j = i; j < rows; ++j) {
      for (let k = 0; k < cols; ++k) {
        arr[k] += matrix[j][k]
      }

      const map = new TreeMap<number, boolean>()
      map.put(0, true)

      let presumRight = 0

      for (const v of arr) {
        presumRight += v

        //用ceiling方法求出来的presumLeft正好满足presumLeft >= presumRight - k
        //而且还是最小的
        const presumLeft = map.ceiling(presumRight - k)

        if (presumLeft !== null) {
          ans = Math.max(ans, presumRight - presumLeft)
        }
        map.put(presumRight, true)
      }
    }
  }

  return ans
}
