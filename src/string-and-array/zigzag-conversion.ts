function convert(s: string, numRows: number): string {
  if (numRows < 2) {
    return s
  }
  const rows: string[] = Array.from<string>({ length: numRows }).fill('')

  let row = 0
  let dir = -1

  for (const c of s) {
    if (row === 0 || row === numRows - 1) {
      dir = -dir
    }
    rows[row] = rows[row] + c
    row += dir
  }

  let ans = ''

  for (let i = 0; i < numRows; i++) {
    ans += rows[i]
  }

  return ans
}
