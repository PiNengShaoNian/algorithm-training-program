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
