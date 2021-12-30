type Rect = {
  height: number
  width: number
}

function largestRectangleArea(heights: number[]): number {
  heights.push(0)
  const n = heights.length
  const stack: Rect[] = []
  let ans = 0
  for (let i = 0; i < n; ++i) {
    let accumulationWdith = 0
    while (stack.length && stack[stack.length - 1].height > heights[i]) {
      const { width, height } = stack.pop()!
      accumulationWdith += width

      ans = Math.max(height * accumulationWdith, ans)
    }

    stack.push({
      height: heights[i],
      width: accumulationWdith + 1,
    })
  }

  heights.pop()

  return ans
}

//单调栈做法
export function maximalRectangle(matrix: string[][]): number {
  const n = matrix.length
  const m = matrix[0].length
  let ans = 0
  const heights: number[] = Array.from<number>({ length: m }).fill(0)
  //累加height，以每个i为柱状图为底部，利用柱状图中的最大矩形来解题
  for (let i = 0; i < n; ++i) {
    for (let j = 0; j < m; ++j) {
      if (matrix[i][j] === '1') {
        ++heights[j]
      } else {
        heights[j] = 0
      }
    }
    ans = Math.max(ans, largestRectangleArea(heights))
  }

  return ans
}
