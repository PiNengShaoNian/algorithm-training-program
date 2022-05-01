//记忆化搜索解法
function PredictTheWinner(nums: number[]): boolean {
  const memo: Record<string, number> = {}
  //turn为1表示A先手，为-1表示B先手
  //Impl(l,r,1)表示在nums[l:r]范围内，在A先手的情况下，A,B都尝试
  //使自己得到的分数最大，最后A,B两者分数的差值是多少
  //我们可以让A赚正分，B赚负分，最后的结果就是他们两的和
  const Impl = (l: number, r: number, turn: number): number => {
    if (l === r) {
      return nums[l] * turn
    }
    const key = l + '-' + r + '-' + turn
    if (typeof memo[key] === 'number') return memo[key]

    const scoreStart = nums[l] * turn + Impl(l + 1, r, -turn)
    const scoreEnd = nums[r] * turn + Impl(l, r - 1, -turn)

    //A,B两人都在这里做出最利于自己的选择
    return (memo[key] =
      turn == 1
        ? //这轮是A做选择，他要选择其中较大的分使自己的分数成为一个更大的正数
          //这样他才能获胜
          Math.max(scoreStart, scoreEnd)
        : //这轮是B做选择，他要选择其中较小的分使自己的分数成为一个更小的负数
          //这样他才能获胜
          Math.min(scoreStart, scoreEnd))
  }

  //A,B两人的分差，只有分差大于等于0,A才能获胜
  return Impl(0, nums.length - 1, 1) >= 0
}

//动态规划解法
function PredictTheWinner1(nums: number[]): boolean {
  //dp[i][j]表示在nums[i:j]区间内先手的那个玩家能比后手的玩家多多少分
  const dp: number[][] = []
  const n = nums.length

  for (let i = 0; i < n; ++i) {
    dp[i] = Array.from<number>({ length: n }).fill(0)
    dp[i][i] = nums[i]
  }

  for (let len = 2; len <= n; ++len) {
    for (let i = 0; i + len <= n; ++i) {
      const j = i + len - 1

      //如果一个人在nums[i:j]区间内选择先手，它可以选择nums[i]或者nums[j]
      //那么我们需要减去一个人在nums[i+1:j]或者nums[i:j-1]区间内先手
      //的最大分数，就是dp[i][j]
      dp[i][j] = Math.max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1])
    }
  }

  //在nums[0:n-1]区间内先手的是A,如果dp[0][n-1]大于等于0，
  //说明A得到的分数更高，A能获胜
  return dp[0][n - 1] >= 0
}
