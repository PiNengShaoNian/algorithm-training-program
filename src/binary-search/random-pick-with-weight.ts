class Solution {
  pre: number[]
  total: number
  constructor(w: number[]) {
    const pre = []
    pre[0] = w[0]
    let total = w[0]
    for (let i = 1; i < w.length; i++) {
      pre[i] = pre[i - 1] + w[i]
      total += w[i]
    }
    this.pre = pre
    this.total = total
  }

  pickIndex(): number {
    const x = Math.floor(Math.random() * this.total) + 1
    return this.binarySearch(x)
  }

  binarySearch(x: number) {
    let low = 0
    let high = this.pre.length - 1
    let ans = -1
    while (low <= high) {
      const mid = low + ((high - low) >> 1)
      if (this.pre[mid] >= x) {
        ans = mid
        high = mid - 1
      } else {
        low = mid + 1
      }
    }
    return ans
  }
}

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(w)
 * var param_1 = obj.pickIndex()
 */
