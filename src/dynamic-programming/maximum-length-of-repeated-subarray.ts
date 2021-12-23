//自己做题,复杂度O(n ^ 3)
export function findLength(nums1: number[], nums2: number[]): number {
  let ans = 0
  const n = nums1.length
  const m = nums2.length

  const getCommonArrayLength = (s1: number, s2: number): number => {
    let ans = 0
    while (s1 < n && s2 < m && nums1[s1] === nums2[s2]) {
      ++ans
      ++s1
      ++s2
    }

    return ans
  }

  for (let i = 0; i < n; ++i) {
    for (let j = 0; j < m; ++j) {
      ans = Math.max(getCommonArrayLength(i, j), ans)
    }
  }

  return ans
}

//动态规划解法，时间复杂度O(n * m)
export function findLength1(nums1: number[], nums2: number[]): number {
  const n = nums1.length
  const m = nums2.length
  //dp[i][j]表示在nums1中以nums1[i]元素为开头的子数组
  //和nums2中以nums2[j]为开头的子数组最大的公共前缀长度
  //A: [1,2,3,2,1]
  //B: [3,2,1,4,7]
  //就比如dp[3][1]就为2,因为数组[2,1]和数组[2,1,4,7]最大的公共前缀长度为2
  
  const dp: number[][] = Array.from({ length: n + 1 }, () =>
    Array.from<number>({ length: m + 1 }).fill(0)
  )

  let ans = 0
  for (let i = n - 1; i >= 0; --i) {
    for (let j = m - 1; j >= 0; --j) {
      dp[i][j] = nums1[i] === nums2[j] ? dp[i + 1][j + 1] + 1 : 0
      ans = Math.max(dp[i][j], ans)
    }
  }

  return ans
}
