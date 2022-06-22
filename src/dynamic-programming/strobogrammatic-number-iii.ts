function strobogrammaticInRange(low: string, high: string): number {
  //自对称的字符，翻转前后都是相等的
  const selfSymmetryChars = ['0', '1', '8']
  //翻转对称的字符对，可以互相翻转得到
  const flipSymmetryPairs = [
    ['6', '9'],
    ['9', '6'],
  ]
  const len1 = low.length
  const len2 = high.length
  //判断a字符串所表示的数字是否小于等于b字符串所表示的数字
  const lessOrEqual = (a: string, b: string) => {
    if (a.length !== b.length) {
      return a.length < b.length
    }
    return a <= b
  }
  //dp1初始化为表示长度为0的旋转对称数
  let dp1 = ['']
  //dp2初始化为表示长度为1的旋转对称数
  let dp2 = ['0', '1', '8']
  let ans = 0
  for (const x of dp2) if (lessOrEqual(x, high) && lessOrEqual(low, x)) ++ans

  for (let i = 2; i <= len2; ++i) {
    const dp: string[] = []
    for (const num of dp1) {
      for (const x of selfSymmetryChars) {
        //长度为i的旋转对称数由长度为i-2的两端添加一个自对称字符x而来
        dp.push(x + num + x)
      }

      for (const [s, e] of flipSymmetryPairs) {
        //长度为i的旋转对称数也可以由长度为i-2的两端添加一对旋转对称字符s,e而来
        dp.push(s + num + e)
      }
    }

    //将dp1更新为长度为i-1的旋转对称数
    dp1 = dp2
    //将dp2更新为长度为i的旋转对称数
    dp2 = dp

    if (i >= len1) {
      for (const x of dp) {
        if (lessOrEqual(x, high) && lessOrEqual(low, x) && x[0] !== '0') ++ans
      }
    }
  }

  return ans
}
