export function maxEnvelopes(envelopes: number[][]): number {
  //可以用最长递增子序列的思路去解题，但是那种思路是和顺序相关的
  //这种求套娃是和顺序无关的，所以我们可以先按宽度排序,将维度将维度
  //降为只有高度，在对信封做一遍最长递增子序列就行
  envelopes.sort((a, b) => a[0] - b[0])

  //dp[i]表示以envelopes[i]为最外层信封他能构成的套娃层数为dp[i]
  const dp: number[] = []
  dp[0] = 1

  let ans = 1
  for (let i = 1; i < envelopes.length; ++i) {
    dp[i] = 1
    for (let j = 0; j < i; ++j) {
      if (
        envelopes[j][0] < envelopes[i][0] &&
        envelopes[j][1] < envelopes[i][1]
      ) {
        dp[i] = Math.max(dp[i], dp[j] + 1)
      }
    }

    ans = Math.max(ans, dp[i])
  }

  return ans
}

export function maxEnvelopes1(envelopes: number[][]): number {
  //按照LIS的思路，用二分查找动态构建最长递增子序列
  //其中tails[i]代表长度为i的最长递增子序列他末尾最小的信封为tails[i]结尾
  const tails: number[][] = []

  //将信封先按宽度升序排序，在此基础上再按高度降序排序,因为按照题意描述相同宽度的
  //信封是不能互相包裹的，而按照高度降序排序后我们就能保证在宽度相同的信封中
  //在依照他们的高度寻找最长递增子序列该子序列的长度不会超过1，这个是符合题意的
  //应为如果超过1那么就代表相同宽度的信封相互嵌套了算出来的答案就是错的
  envelopes.sort((a, b) => {
    if (a[0] !== b[0]) {
      return a[0] - b[0]
    }

    return b[1] - a[1]
  })

  tails[1] = envelopes[0]
  let len = 1

  for (let i = 1; i < envelopes.length; ++i) {
    if (tails[len][1] < envelopes[i][1]) {
      tails[++len] = envelopes[i]
    } else {
      let l = 1
      let r = len
      let pos = 0

      while (l <= r) {
        const mid = (l + r) >> 1

        if (tails[mid][1] < envelopes[i][1]) {
          l = mid + 1
          pos = mid
        } else {
          r = mid - 1
        }
      }

      tails[pos + 1] = envelopes[i]
    }
  }

  return len
}
