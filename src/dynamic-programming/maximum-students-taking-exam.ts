export function maxStudents(seats: string[][]): number {
  const memo: number[][] = [[], [], [], [], [], [], [], []]
  const compressedSeats: number[] = []
  const width = seats[0].length
  const rows = seats.length
  const compress = (row: number) => {
    const seat = seats[row]
    let ans = 0
    for (let i = 0; i < width; ++i) {
      ans <<= 1
      if (seat[i] === '.') {
        ++ans
      }
    }

    return ans
  }

  for (let i = 0; i < rows; ++i) {
    compressedSeats[i] = compress(i)
  }

  //f(X,row)表示，在row为起始的排布X中，最多能够接受的学生数
  //因为后续的状态是更去第row行而来的，所以记录该排布时只需要记录第row行的
  //座位状态
  const f = (X: number, row: number): number => {
    if (memo[row][X] !== undefined) return memo[row][X]

    let ans = 0
    for (let scheme = 0; scheme < 1 << width; ++scheme) {
      if (
        //~X表示那些不可以坐人的座位，
        // scheme & ~X表示在这种不可用的座位上，安排了学生
        //这种状态是非法状态需要跳过
        scheme & ~X ||
        //同一排中连续的座位不能安排有学生，否则就是无效状态
        scheme & (scheme << 1)
      )
        continue

      let rowCount = 0

      for (let i = 0; i < width; ++i) {
        //这个安排(scheme)是合法的，计算这一行中可以坐几个学生
        if (scheme & (1 << i)) ++rowCount
      }

      if (row === rows - 1) {
        //最后一行，也就是递归的终止条件，直接更新答案
        ans = Math.max(ans, rowCount)
      } else {
        let nextSeats = compressedSeats[row + 1]
        //这一行中选中的一个位置，那么在下一行中和他相邻的位置就需要被标记为不可用
        nextSeats &= ~(scheme >> 1)
        nextSeats &= ~(scheme << 1)

        ans = Math.max(ans, rowCount + f(nextSeats, row + 1))
      }
    }

    return (memo[row][X] = ans)
  }

  return f(compressedSeats[0], 0)
}
