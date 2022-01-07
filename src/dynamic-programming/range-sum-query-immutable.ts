export class NumArray {
  private presum: number[] = []
  constructor(nums: number[]) {
    const { presum } = this
    const n = nums.length
    presum[0] = 0

    for (let i = 0; i < n; ++i) {
      presum[i + 1] = presum[i] + nums[i]
    }
  }

  sumRange(left: number, right: number): number {
    return this.presum[right + 1] - this.presum[left]
  }
}
