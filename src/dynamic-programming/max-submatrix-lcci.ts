export function maxSubArray(nums: number[]): [number, number, number] {
  //dp[i]表示以nums[i]结尾最大的子序和dp[i]
  const dp: number[] = []

  dp[0] = nums[0]
  let max = nums[0]
  let left = 0
  let right = 0
  let prevLeft = -1

  for (let i = 1; i < nums.length; ++i) {
    if (dp[i - 1] < 0) {
      dp[i] = nums[i]
      //如果一个是一个单调递减的数组我们需要记录下之前的左端点
      //以免错过正确答案
      if (left <= right) prevLeft = left
      //重新记录起点坐标
      left = i
    } else {
      dp[i] = nums[i] + dp[i - 1]
    }

    if (dp[i] > max) {
      //更新最大值的终点坐标
      max = dp[i]
      right = i
    }
  }

  return [max, left > right ? prevLeft : left, right]
}

function getMaxMatrix(matrix: number[][]): number[] {
  const rows = matrix.length
  const cols = matrix[0].length
  let max = matrix[0][0]
  const ans: number[] = [0, 0, 0, 0]
  //通过枚举起始行和终止行然后再通过最大子数组和求出起始列和末尾列
  for (let i = 0; i < rows; ++i) {
    const subMatrix: number[] = Array.from<number>({ length: cols }).fill(0)
    for (let j = i; j < rows; ++j) {
      for (let k = 0; k < cols; ++k) {
        subMatrix[k] += matrix[j][k]
      }

      const [cand, left, right] = maxSubArray(subMatrix)

      if (cand > max) {
        max = cand
        ans[0] = i //row1
        ans[1] = left //col1
        ans[2] = j //row2
        ans[3] = right //col2
      }
    }
  }

  return ans
}
