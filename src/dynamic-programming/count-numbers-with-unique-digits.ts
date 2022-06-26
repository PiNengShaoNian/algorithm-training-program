export function countNumbersWithUniqueDigits(n: number): number {
  //范围[0,1) ===> {0}
  if (n === 0) return 1
  //[0,10) ===> {0,1,2,3,4,5,6,7,8,9}
  if (n === 1) return 10

  let ans = 10
  let cur = 9

  //长度大于等于2，且满足条件的数字数量，比如要求
  //长度为2的数字的数量，那么我们第一位就可以去1至9，第二位就可以去0至9，
  //长度越长后面位置可选的数字越少
  for (let i = 0; i < n - 1; ++i) {
    cur *= 9 - i
    ans += cur
  }

  return ans
}
