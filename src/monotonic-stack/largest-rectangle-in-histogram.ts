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

  return ans
}
