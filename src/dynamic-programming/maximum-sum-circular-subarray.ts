export function maxSubarraySumCircular(nums: number[]): number {
  //循环数组可以通过将nums复制一倍接在nums尾部模拟出来，然后这题就和
  //最大子数组和的思路差不多了，不过要控制前缀和的
  //区间大小 小于于等于n + 1即可
  //通过护一个n + 1大小的用单调队列然后每次用presum[i] - presum[queue[0]]
  //更新答案
  const n = nums.length

  for (let i = 0; i < n; ++i) {
    nums.push(nums[i])
  }

  const presum: number[] = []
  presum[0] = 0
  for (let i = 1; i < nums.length; ++i) {
    presum[i] = presum[i - 1] + nums[i - 1]
  }
  let ans = nums[0]
  //javascript中的数组当队列使用时，在数据量较大的情况下
  //性能非常糟糕，可以使用专门的数据结构替换数组以提升性能
  const deque: number[] = []
  deque.push(0)
  for (let i = 1; i < presum.length; ++i) {
    //把超出窗口范围前缀和的去掉，注意在nums中[l,r]范围的区间和，
    //需要用presum[r + 1] - presum[l]获得，所以实际上滑动窗口的大小
    //应该是n + 1
    while (deque.length && deque[0] < i - n) {
      deque.shift()
    }

    ans = Math.max(presum[i] - presum[deque[0]], ans)

    //把又大又老的前缀和去了，只留下又小又年轻的
    while (deque.length && presum[deque[deque.length - 1]] >= presum[i]) {
      deque.pop()
    }

    deque.push(i)
  }

  return ans
}
