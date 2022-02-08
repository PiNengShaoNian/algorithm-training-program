//动态规划解法
function maxTurbulenceSize(arr: number[]): number {
  const n = arr.length
  if (n === 1) return 1

  //dp[i - 1]是否小于dp[i - 2]
  let less = false
  const dp: number[] = []
  dp[0] = 1
  dp[1] = 2
  if (arr[0] === arr[1]) {
    dp[1] = 1
  } else if (arr[0] > arr[1]) {
    less = true
  }

  let ans = dp[1]

  for (let i = 2; i < n; ++i) {
    dp[i] = 1
    if (arr[i] !== arr[i - 1]) {
      // a[i - 2]  >  a[i - 1] <   c
      if (less && arr[i - 1] < arr[i]) {
        dp[i] = dp[i - 1] + 1
        less = false
      }
      // a[i - 2]  <  a[i - 1] >  c
      else if (!less && arr[i - 1] > arr[i]) {
        dp[i] = dp[i - 1] + 1
        less = true
      } else {
        //无法与之前的构成湍流子数组,
        //但是dp[i]和dp[i - 1]不相等所以可以构成长度为2的湍流子数组
        dp[i] = 2
      }
    }

    ans = Math.max(ans, dp[i])
  }

  return ans
}

//滑动窗口解法
export function maxTurbulenceSize1(arr: number[]): number {
  const n = arr.length

  let l = 0
  let r = 0
  let ans = 1
  while (r < n - 1) {
    if (l === r) {
      //窗口大小为1，尝试向右拓展，如果发现当前数字等于下一个数字
      //则l和r都向右移，否则只有r向右移动
      if (arr[l] === arr[l + 1]) {
        ++l
      }

      ++r
    } else {
      if (arr[r - 1] > arr[r] && arr[r] < arr[r + 1]) {
        //满足条件窗口向右移动一位
        ++r
      } else if (arr[r - 1] < arr[r] && arr[r] > arr[r + 1]) {
        //满足条件窗口向右移动一位
        ++r
      } else {
        //[r−1,r+1] 无法构成「湍流子数组」，
        //当 l<r 时，[l,r+1] 也无法构成「湍流子数组」，
        //因此需要将 left 移到 right，即令 l = r。
        l = r
      }
    }

    ans = Math.max(ans, r - l + 1)
  }

  return ans
}
