//单调队列解法
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

//动态规划解法
export function maxSubarraySumCircular1(nums: number[]): number {
  //循环列表中最大的数组和无非就只用两种情况一种最大和在中间区域,
  //比如[-3,3,-3],有可能在两边[3,-3,3],第一种情况中的做法和求最大和子数组
  //一模一样,第二种情况中最大的子数组和等于数组的sum减掉最小和子数组和

  const dpMin: number[] = []
  const dpMax: number[] = []
  let sum = (dpMin[0] = dpMax[0] = nums[0])

  for (let i = 1; i < nums.length; ++i) {
    dpMin[i] = Math.min(dpMin[i - 1] + nums[i], nums[i])
    dpMax[i] = Math.max(dpMax[i - 1] + nums[i], nums[i])
    sum += nums[i]
  }

  const min = Math.min(...dpMin)
  const max = Math.max(...dpMax)

  return Math.max(
    //最大和由中间的元素累加而来
    max,
    //最大和由在两边的元素相加而来,注意在全是负数的数组中比如[-2]那么sum - min为0
    //但是实际的答案为-2所以特别处理一下这种情况，如果一个循环数组全为负数
    //那么他的最大子数组和就是其中最大的那个元素
    sum - min === 0 ? max : sum - min
  )
}
