/**
 Do not return anything, modify matrix in-place instead.
 */
function rotate(matrix: number[][]): void {
  const n = matrix.length

  for (let i = 0; i < n >> 1; i++) {
    for (let j = 0; j < (n + 1) >> 1; j++) {
      // 第i行，第j列的元素经过一次90度的旋转后处于第j行，n - i - 1列
      // 为了保证每个位置只被旋转一次我们选择之旋转左上四分之一的元素
      const a = matrix[i][j]
      const b = matrix[j][n - i - 1]
      const c = matrix[n - i - 1][n - j - 1]
      const d = matrix[n - j - 1][i]

      matrix[j][n - i - 1] = a
      matrix[n - i - 1][n - j - 1] = b
      matrix[n - j - 1][i] = c
      matrix[i][j] = d
    }
  }
}
