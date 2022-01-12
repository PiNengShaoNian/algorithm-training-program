export function matrixBlockSum(mat: number[][], k: number): number[][] {
  const rows = mat.length
  const cols = mat[0].length
  const presum: number[][] = []

  const getNum = (row: number, col: number): number => {
    if (col < 0 || row < 0) return 0

    row = Math.min(rows - 1, row)
    col = Math.min(cols - 1, col)

    return presum[row][col]
  }

  for (let i = 0; i < rows; ++i) {
    presum[i] = []
    for (let j = 0; j < cols; ++j) {
      presum[i][j] =
        getNum(i - 1, j) + getNum(i, j - 1) + mat[i][j] - getNum(i - 1, j - 1)
    }
  }

  const ans: number[][] = []

  //左上角[i-k,j-k]
  //右下角[i+k,j+k]
  for (let i = 0; i < rows; ++i) {
    ans[i] = []
    for (let j = 0; j < cols; ++j) {
      ans[i][j] =
        getNum(i + k, j + k) -
        getNum(i + k, j - k - 1) -
        getNum(i - k - 1, j + k) +
        getNum(i - k - 1, j - k - 1)
    }
  }

  return ans
}
