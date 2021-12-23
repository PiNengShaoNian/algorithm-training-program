//自己做题O(n * m)
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
