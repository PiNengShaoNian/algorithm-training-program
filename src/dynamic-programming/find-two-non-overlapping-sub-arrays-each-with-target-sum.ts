export function minSumOfLengths(arr: number[], target: number): number {
  //dp[i]表示在arr的[0,i)范围内满足条件的数组最小长度，其中i的范围为[0,n]
  //比如当arr为[1,1,1,3,4]，target为3时dp[4]等于1,因为子数组[1,1,1]和[3]
  //都满足条件但是子数组[3]的长度更短为1
  const dp: number[] = []
  let l = 0
  let r = 0
  let ans = Infinity
  const n = arr.length
  let sum = 0
  dp[0] = Infinity

  for (; r < n; ++r) {
    sum += arr[r]

    while (sum > target) {
      sum -= arr[l]
      ++l
    }

    if (sum === target) {
      //子数组arr[l:r]满足条件，其中l和r的范围都是[0,n)
      //所以该数组的实际长度为r - l + 1
      const len = r - l + 1
      //更新答案，该数组作为两个数组中的其中一个然后再从l之前选一个，
      //dp[l]中保存的就是l之前,满足条件的子数组中最短的那个长度
      ans = Math.min(ans, len + dp[l])
      dp[r + 1] = Math.min(dp[r], len)
    } else {
      dp[r + 1] = dp[r]
    }
  }

  return ans <= n ? ans : -1
}
