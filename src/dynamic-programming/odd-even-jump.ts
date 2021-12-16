export function oddEvenJumps(arr: number[]): number {
  //nextEven[i]表示在i进行偶数次跳跃能跳到nextEven[i]
  const nextEven: number[] = []
  //nextOdd[i]表示在i进行奇数次跳跃能跳到nextOdd[i]
  const nextOdd: number[] = []
  const stack: number[] = []
  const n = arr.length
  const order: number[] = Array.from({ length: n }, (_, i) => i)

  //注意跳跃是1,2,3,4....这样跳跃的，所以第一次跳跃为奇数跳
  //由题意描述可以知道给定一个数组对于每个nextEven[i]和每个nextOdd[i]
  //的值都是确定的，关键是怎么求出这两个序列以方便后面的递推
  //考虑该数组  [3,2,4,3,3]我们如果要求出每个下标i对应的下标j
  //(其中i < j, arr[i] <= arr[j],并且arr[j]是满足条件中最小的
  //,也就是在i位置进行奇数跳的终点)
  //我们可以只保存下标得到数组order
  //[0,1,2,3,4]，以元素大小排序order数组能得到 sortedOrder
  //[1 (2),0 (3),3 (3),4 (3),2 (4)]
  //然后我们遍历sortedOrder每遍历到一个小标sortedOrder[i]，如果发现
  //sortedOrder[0,i - 1]中的k(k也是一个下标)小于sortedOrder[i]
  //那么就更新nextOdd[k] = sortedOrder[i]
  //比如我们可以发现3下标对应的位置,就是0,1下标的奇数跳终点
  //下标4,和2则没有对应的j
  //具体实现我们可以用单调递减的栈维护这样的序列,每当遇到比栈顶元素
  //大的sortedOrder[i]我们就更新答案
  //最后栈中还没出栈的元素就是那些不能进行奇数跳的位置,比如[2,4]

  order.sort((a, b) => {
    if (arr[a] !== arr[b]) return arr[a] - arr[b]
    //为了求出的位置是满足条件,并且是最靠前的元素我们以下标作为第二排序标准
    //比如[1,3,3,3]我们肯定希望nextOdd[0] = 1，而不是2,3
    else return a - b
  })

  for (let i = 0; i < n; ++i) {
    while (stack.length && stack[stack.length - 1] < order[i]) {
      nextOdd[stack.pop()!] = order[i]
    }

    stack.push(order[i])
  }

  while (stack.length) nextOdd[stack.pop()!] = -1

  //求nextEven的原理也差不多，只不过排序改为降序
  order.sort((a, b) => {
    if (arr[a] !== arr[b]) return arr[b] - arr[a]
    else return a - b
  })

  for (let i = 0; i < n; ++i) {
    while (stack.length && stack[stack.length - 1] < order[i]) {
      nextEven[stack.pop()!] = order[i]
    }

    stack.push(order[i])
  }

  while (stack.length) nextEven[stack.pop()!] = -1

  let ans = 1
  //dp[i][0]表示在i点进行偶数次跳跃，是否能到达终点
  //dp[i][1]表示在i点进行奇数次跳跃，是否能到达终点
  const dp: boolean[][] = Array.from({ length: n }, () => [])
  dp[n - 1][0] = dp[n - 1][1] = true

  for (let i = n - 2; i >= 0; --i) {
    let next = nextOdd[i]

    //只有在奇数跳的时候可以累加答案，应为他是每个起点的第一次跳跃，
    //如果next有解的话答案就能直接加1
    if (next !== -1 && dp[next][0]) {
      //在i位置做奇数次跳跃那么就必须在next位置做偶数次跳跃
      //所以如果dp[next][0]为true的话答案就能加1
      ++ans
      dp[i][1] = true
    }

    next = nextEven[i]

    //在偶数是跳跃时不能累加答案，应为他不是第一次跳跃，就算你在这能跳到终点
    //也不能保证前面的一次奇数次跳跃能跳到i
    if (next !== -1 && dp[next][1]) {
      dp[i][0] = true
    }
  }

  return ans
}
