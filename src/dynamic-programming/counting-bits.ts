export function countBits(n: number): number[] {
  //这题的递推公式很巧妙，如果不用递推的方式那么每个数
  //都得去枚举一下他1的个数那么时间复杂度就为位宽w乘n
  //O(w*n),如果数据类型为int那么时间复复杂度就为O(32n)
  //其实我们在计算一个数中1的个数时，可以利用现有的信息
  //节省大量的计算,比如要知道数字i中一的个数只需要知道
  //i - lowbit(i)中一的个数然后在加一就行
  //其中lowbit(x) = x & -x
  //lowbit(0b111010) = 0b000010  
  //lowbit(0b110000) = 0b010000
  
  
  const dp: number[] = []
  dp[0] = 0
  for (let i = 1; i <= n; ++i) {
    dp[i] = dp[i - (i & -i)] + 1
  }

  return dp
}
