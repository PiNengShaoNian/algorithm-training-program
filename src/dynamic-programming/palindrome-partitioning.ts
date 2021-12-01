//动态规划预处理字符串，然后回溯收集答案
export function partition(s: string): string[][] {
  //dp[i][j]为true表示s[i,j]所代表的字串是回文串
  const dp: boolean[][] = []
  const n = s.length

  for (let i = 0; i < n; ++i) {
    dp[i] = []
    for (let j = 0; j < n; ++j) {
      dp[i][j] = true
    }
  }

  //难点，像这种由中间向两端递推的状态，要保证前置状态
  //已经确定需要i,j一个递增一个递减
  for (let i = n - 1; i >= 0; --i) {
    for (let j = i + 1; j < n; ++j) {
      dp[i][j] = s[i] === s[j] && dp[i + 1][j - 1]
    }
  }
  const ans: string[][] = []
  const dfs = (i: number, path: string[]) => {
    if (i === n) {
      ans.push(path.slice())
      return
    }
    for (let j = i; j < n; ++j) {
      if (dp[i][j]) {
        path.push(s.substr(i, j - i + 1))
        dfs(j + 1, path)
        path.pop()
      }
    }
  }

  dfs(0, [])

  return ans
}
