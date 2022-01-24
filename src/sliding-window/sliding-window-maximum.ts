export function maxSlidingWindow(nums: number[], k: number): number[] {
  const queue: number[] = []
  const n = nums.length
  const ans: number[] = []
  for (let i = 0; i < n; ++i) {
    while (queue.length && queue[0] < i - k + 1) {
      queue.shift()
    }

    while (queue.length && nums[queue[queue.length - 1]] <= nums[i]) queue.pop()

    queue.push(i)

    if (i - k + 1 >= 0) {
      ans.push(nums[queue[0]])
    }
  }

  return ans
}
