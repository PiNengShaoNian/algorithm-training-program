export function minSteps(n: number): number {
  //dp[i][j]表示要达到记事本上有i个字符，粘贴板上有j个字符这个状态，需要的最小的操作数
  //最后一次操作可能为Copy All或者Paste
  //A. 如果为Paste操作则j的有效状态最大为i / 2,因为大于这个数记事本里的字符就会大于i属于非法状态
  //   所以j在[0,i / 2]之间枚举就行
  //B. 如果为Copy All操作则i = j
  const dp: number[][] = []

  for (let i = 0; i <= n; ++i) {
    dp[i] = Array.from<number>({ length: n + 1 }).fill(Infinity)
  }

  dp[1][0] = 0
  dp[1][1] = 1

  for (let i = 2; i <= n; ++i) {
    let min = Infinity
    //Paste操作,i != j,j <= i / 2
    for (let j = 0; j <= i >> 1; ++j) {
      //Paste前记事本里有i-j个字符，粘贴板里有j个字符
      //Paste后记事本中有i个字符，粘贴板里有j个字符
      dp[i][j] = dp[i - j][j] + 1
      min = Math.min(min, dp[i][j])
    }
    //Copy All操作,i == j
    //复制之前剪切板里的字符为x，其中0 <= x < i
    //这些dp[i][x]状态，正是上面循环里边遍历的dp[i][j]，我们取他们之中
    //最小的那个min
    dp[i][i] = min + 1
  }

  let ans = Infinity

  for (let i = 0; i <= n; ++i) {
    ans = Math.min(ans, dp[n][i])
  }

  return ans
}
