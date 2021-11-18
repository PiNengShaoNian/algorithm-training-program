export class NumArray {
  /**
       数据存储 [1-n] 
      */
  private a: number[] = []
  /**
         树节点 [1-n]
       */
  private c: number[] = []
  private n: number
  constructor(nums: number[]) {
    this.n = nums.length
    
    //树状数组必须提前初始化好,应为待会add的时候会访问一个节点的所有父节点
    this.c = Array.from<number>({ length: this.n + 1 }).fill(0)

    for (let i = 1; i <= nums.length; ++i) {
      this.a[i] = nums[i - 1]
      this.add(i, nums[i - 1])
    }
  }

  //将x添加到c[i]以及他的父结点中
  private add(pos: number, delta: number): void {
    for (; pos <= this.n; pos += pos & -pos) {
      this.c[pos] += delta
    }
  }

  //将val转换为delta就是调用add了
  update(index: number, val: number): void {
    //注意树状数组的索引为[1,n]所以在这里要将index + 1
    const delta = val - this.a[index + 1]
    this.add(index + 1, delta)
    this.a[index + 1] = val
  }

  //获取c[i]节点所代表的前缀和
  private query(i: number) {
    let ans = 0

    for (; i > 0; i -= i & -i) {
      ans += this.c[i]
    }
    return ans
  }

  //[left,right] = [0, n - 1] 要转换为[1, n]
  //其中[left,right]的区间和就为query(right) - query(left - 1)
  sumRange(left: number, right: number): number {
    return this.query(right + 1) - this.query(left)
  }
}
