//自顶向下解法,时间复杂度O(2^N),其中N为数组长度
export function findTargetSumWays(nums: number[], target: number): number {
  const memo: number[][] = Array.from({ length: 21 }, () => [])
  const n = nums.length
  //Impl(i,j)表示在数组nums[i:n-1]区间内，能组成的目标和等于j的表达式数量
  const Impl = (depth: number, sum: number): number => {
    if (depth >= n) {
      return sum === target ? 1 : 0
    }

    if (memo[depth][sum] !== undefined) return memo[depth][sum]

    let ans = 0

    ans += Impl(depth + 1, sum + nums[depth])
    ans += Impl(depth + 1, sum - nums[depth])

    return (memo[depth][sum] = ans)
  }

  return Impl(0, 0)
}

export function findTargetSumWays1(nums: number[], target: number): number {
  const n = nums.length
  let sum = 0

  for (let i = 0; i < n; ++i) {
    sum += nums[i]
  }

  //假设在一个符合条件的表达式中选择了负号的数字的和neg
  //数组所有元素的和为sum,那么选择了正号的数字的和就为pos = sum - neg
  //其中有 pos - neg        = target
  //    = (sum - neg) - neg = target
  //所以neg = (sum - target) / 2
  //由于nums中所有数字都为正整数所以neg也必定为正整数，所以sum - target为偶数
  //现在问题就变为从nums种选若干个数字且他们的大小为neg也就是(sum - target) /2
  const diff = sum - target

  //如果neg不为正整数则直接返回0
  if (diff & 1 || diff < 0) return 0

  const neg = diff >> 1
  const dp: number[] = Array.from<number>({ length: neg + 1 }).fill(0)
  dp[0] = 1
  for (let i = 0; i < n; ++i) {
    const num = nums[i]
    for (let j = neg; j >= num; --j) {
      dp[j] += dp[j - num]
    }
  }

  return dp[neg]
}
