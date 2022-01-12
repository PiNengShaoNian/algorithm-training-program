const subarraySum = (nums: number[], target: number): number => {
  let ans = 0
  let presum = 0
  let map = new Map<number, number>()
  map.set(0, 1)

  for (let i = 0; i < nums.length; ++i) {
    presum = presum + nums[i]

    if (map.has(presum - target)) {
      ans += map.get(presum - target)!
    }

    map.set(presum, (map.get(presum) ?? 0) + 1)
  }

  return ans
}

export function numSubmatrixSumTarget(
  matrix: number[][],
  target: number
): number {
  const rows = matrix.length
  const cols = matrix[0].length
  let ans = 0

  for (let row1 = 0; row1 < rows; ++row1) {
    const sum: number[] = Array.from({ length: cols }).fill(0) as number[]
    for (let row2 = row1; row2 < rows; ++row2) {
      for (let col = 0; col < cols; ++col) {
        sum[col] += matrix[row2][col]
      }

      ans += subarraySum(sum, target)
    }
  }

  return ans
}
