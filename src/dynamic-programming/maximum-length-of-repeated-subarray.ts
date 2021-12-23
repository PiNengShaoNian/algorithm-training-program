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

//滑动窗口解法
export function findLength2(nums1: number[], nums2: number[]): number {
  //用nums1中的开头元素去对其nums2中的每个元素，在求其中最长的公共子数组
  //对nums2也进行相同的操作
  const n = nums1.length
  const m = nums2.length
  const maxLength = (s1: number, s2: number): number => {
    let ans = 0
    let k = 0
    let i = 0
    while (s1 + i < n && s2 + i < m) {
      if (nums1[s1 + i] === nums2[s2 + i]) {
        ++k
      } else {
        k = 0
      }

      ++i
      ans = Math.max(ans, k)
    }

    return ans
  }

  let ans = 0
  for (let i = 0; i < n; ++i) {
    ans = Math.max(ans, maxLength(i, 0))
  }

  for (let i = 0; i < m; ++i) {
    ans = Math.max(ans, maxLength(0, i))
  }

  return ans
}

//滚动hash解法
export function findLength3(nums1: number[], nums2: number[]): number {
  const mod = 1000000009
  const base = 113
  const n = nums1.length
  const m = nums2.length
  const myPow = (_: number, n: number) => {
    let ans = 1n
    let x = BigInt(_)
    const m = BigInt(mod)
    while (n) {
      if (n & 1) {
        ans = (ans * x) % m
      }

      //这行代码会爆double,所以先把x声明成bigint类型返回的时候在转回double
      x = (x * x) % m
      n >>= 1
    }

    return parseFloat(ans + '')
  }
  const check = (len: number): boolean => {
    const p13331 = myPow(base, len - 1)
    const hashBuckets1 = new Set<number>()

    let hash1 = 0
    for (let i = 0; i < len; ++i) {
      hash1 = (hash1 * base + nums1[i]) % mod
    }

    hashBuckets1.add(hash1)

    for (let i = len; i < n; ++i) {
      hash1 =
        (((hash1 - ((nums1[i - len] * p13331) % mod) + mod) % mod) * base +
          nums1[i]) %
        mod
      hashBuckets1.add(hash1)
    }

    let hash2 = 0

    for (let i = 0; i < len; ++i) {
      hash2 = (hash2 * base + nums2[i]) % mod
    }

    if (hashBuckets1.has(hash2)) return true

    for (let i = len; i < m; ++i) {
      hash2 =
        (((hash2 - ((nums2[i - len] * p13331) % mod) + mod) % mod) * base +
          nums2[i]) %
        mod
      if (hashBuckets1.has(hash2)) return true
    }

    return false
  }

  let l = 1
  let r = Math.min(nums1.length, nums2.length)
  let ans = 0
  while (l <= r) {
    const mid = l + ((r - l) >> 1)
    if (check(mid)) {
      ans = mid
      l = mid + 1
    } else {
      r = mid - 1
    }
  }

  return ans
}
