//题解https://leetcode.cn/problems/number-of-digit-one/solution/gong-shui-san-xie-jiang-shu-wei-dp-wen-t-c9oi/
export function countDigitOne(n: number): number {
  const s = n.toString()
  const m = s.length

  // 计算第 i 位前缀代表的数值，和后缀代表的数值
  // 例如 abcde 则有 ps[2] = ab; ss[2] = de
  const ss: number[] = Array.from<number>({ length: m }).fill(0)
  const ps: number[] = Array.from<number>({ length: m }).fill(0)
  ss[0] = +s.slice(1)
  for (let i = 1; i < m - 1; ++i) {
    ps[i] = +s.slice(0, i)
    ss[i] = +s.slice(i + 1)
  }
  ps[m - 1] = +s.slice(0, m - 1)

  let ans = 0
  //枚举位置i，假设第i位为1，枚举其他位数的可能选择然后将符合条件的答案累加到ans中
  for (let i = 0; i < m; ++i) {
    let x = +s[i]
    const len = m - i - 1

    //先计算该位前面的部分小于原数字的情况
    //这种情况下后缀可以随便取，前缀可以取[0, ps[i])
    let tot = ps[i] * Math.pow(10, len)

    //下面的计算该位前面的部分等于原数字的情况
    if (x === 0) {
      // 原数字这个位置为0，但是我们已经假设了这个位置为1，所以这个分支不会贡献答案
    } else if (x === 1) {
      //如果数字这个位置为1，且前缀已经选择了等于原数字，那么为了保证数字一定小于原数字，后缀可以取[0, ss[i]]
      //总共由ss[i] + 1个
      tot += ss[i] + 1
    } else {
      //如果原数字这个位置大于1，那么我们的后缀可以随便取，总共有Math.pow(10,len)个取法
      tot += Math.pow(10, len)
    }

    ans += tot
  }

  return ans
}
