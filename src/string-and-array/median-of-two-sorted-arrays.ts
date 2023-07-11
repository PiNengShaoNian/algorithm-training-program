function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
  if (nums1.length > nums2.length) return findMedianSortedArrays(nums2, nums1)

  const n = nums1.length
  const m = nums2.length
  const leftTotal = Math.floor((n + m + 1) / 2)
  let left = 0
  let right = n
  let median1 = 0
  let median2 = 0

  while (left <= right) {
    const i = left + Math.floor((right - left) / 2)
    const j = leftTotal - i

    const num_i = i === n ? Infinity : nums1[i]
    const num_im = i === 0 ? -Infinity : nums1[i - 1]
    const num_j = j === m ? Infinity : nums2[j]
    const num_jm = j === 0 ? -Infinity : nums2[j - 1]

    if (num_im <= num_j) {
      left = i + 1
      median1 = Math.max(num_im, num_jm)
      median2 = Math.min(num_i, num_j)
    } else {
      right = i - 1
    }
  }

  return (n + m) % 2 === 0 ? (median2 + median1) / 2 : median1
}
