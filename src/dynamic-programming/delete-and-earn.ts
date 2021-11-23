export function deleteAndEarn(nums: number[]): number {
  //可以用抢家劫舍的思路来做这题
  //比如这样的数组[1,1,2,2,2,3,3]，我们可以先生成这样的二元组数组
  //[[1,2],[2,3],[3,2]]第一个存元素的值第二个存他的数量，然后用
  //抢家劫舍的思路抢了这家就不能抢旁边的两家来作题,不过这里两边能不能
  //抢变成了判断数字是不是相差等于1
  nums.sort((a, b) => a - b)

  const numCountPairts: [num: number, count: number][] = []

  for (const x of nums) {
    const top = numCountPairts[numCountPairts.length - 1]
    if (!top || top[0] !== x) {
      numCountPairts.push([x, 1])
    } else {
      ++top[1]
    }
  }

  if (numCountPairts.length === 1)
    return numCountPairts[0][0] * numCountPairts[0][1]

  //dp[i]为只在numCountPairts的[0,i]区间内删除数字能获得的最大点数
  const dp: number[] = []
  dp[0] = numCountPairts[0][0] * numCountPairts[0][1]
  if (Math.abs(numCountPairts[0][0] - numCountPairts[1][0]) === 1) {
    dp[1] = Math.max(dp[0], numCountPairts[1][0] * numCountPairts[1][1])
  } else {
    dp[1] = dp[0] + numCountPairts[1][0] * numCountPairts[1][1]
  }

  for (let i = 2; i < numCountPairts.length; ++i) {
    dp[i] = Math.max(
      //不删除numCountPairts[i],那点数和dp[i - 1]相同
      dp[i - 1],
      Math.abs(numCountPairts[i - 1][0] - numCountPairts[i][0]) === 1
        ? //删除numCountPairts[i],并且和前一个数字只相差1，需要忽略前一个数字
          dp[i - 2] + numCountPairts[i][0] * numCountPairts[i][1]
        : //删除numCountPairts[i],并且和前一个数字相差大于1，不需要忽略前一个数字
          dp[i - 1] + numCountPairts[i][0] * numCountPairts[i][1]
    )
  }

  return dp[numCountPairts.length - 1]
}

function rob1(nums: number[]): number {
  if (nums.length === 1) return nums[0]
  //dp[i]表示只在前i + 1家偷能获得的最大收益
  const dp: number[] = [nums[0], Math.max(nums[0], nums[1])]

  for (let i = 2; i < nums.length; ++i) {
    dp[i] = Math.max(
      // 不偷这家,那就能在[0, i-1]区间内偷
      dp[i - 1],
      //偷这家，那之前就只能在[0,i-2]区间内偷
      nums[i] + dp[i - 2]
    )
  }

  return dp[nums.length - 1]
}

export function deleteAndEarn1(nums: number[]): number {
  //甚至可以把数据格式完全转换成抢劫劫舍的格式
  //nums中的一个数x他的数量为c那么删除他能得到的点数就为c * x
  //我们把c * x存在sum[x]中,如果删除了sum[x]那么sum[x - 1]
  //和sum[x + 1]就不能被删除了,这里如果把删除换成抢劫是不是
  //就是抢家劫舍原题
  let max = nums[0]

  for (let i = 1; i < nums.length; ++i) {
    max = Math.max(nums[i], max)
  }

  const sum: number[] = Array.from<number>({ length: max + 1 }).fill(0)

  for (const x of nums) {
    sum[x] += x
  }

  return rob1(sum)
}
