type Rect = {
  height: number
  width: number
}

export function largestRectangleArea(heights: number[]): number {
  heights.push(0)
  const n = heights.length
  const stack: Rect[] = []
  let ans = 0
  for (let i = 0; i < n; ++i) {
    let accumulationWidth = 0
    while (stack.length && stack[stack.length - 1].height > heights[i]) {
      const { width, height } = stack.pop()!
      accumulationWidth += width

      ans = Math.max(height * accumulationWidth, ans)
    }

    stack.push({
      height: heights[i],
      width: accumulationWidth + 1,
    })
  }

  return ans
}
