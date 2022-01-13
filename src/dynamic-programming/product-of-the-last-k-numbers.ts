export class ProductOfNumbers {
  private prefix: number[] = [1]

  constructor() {}

  add(num: number): void {
    if (!num) {
      this.prefix = [1]
      return
    }
    const { prefix } = this
    const last = prefix[prefix.length - 1]
    prefix.push(last * num)
  }

  getProduct(k: number): number {
    const { prefix } = this
    const n = prefix.length
    if (n === 1 || n - k - 1 < 0) return 0
    return prefix[n - 1] / prefix[n - k - 1]
  }
}
