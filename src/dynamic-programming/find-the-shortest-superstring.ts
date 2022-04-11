export function shortestSuperstring(words: string[]): string {
  //该题要求包含所有单词的的子串，所以可以枚举出单词所有可能的排列，然后在将他们组合起来
  //在组合时不是简单的拼接，两个有重叠的部分还要去除重叠的部分比如单词[ab,bc]就可以组合为abbc
  //可以去掉他们重复的部分变为abc依然是满足题意的
  //所以我们我们要求的答案就是所有单词排列中重叠部分最长的那个排列

  //overlaps[i][j]表示words[i]和words[j]重叠的部分的长度
  //比如words[i]为abc，words[j]为bcd，那他们重叠的部分就是bc，所以overlaps[i][j]就是2
  const overlaps: number[][] = []
  const n = words.length
  for (let i = 0; i < n; ++i) {
    overlaps[i] = []
    //这里也可以不设置，应为overlaps[i][i]这种状态我们永远都用不到
    overlaps[i][i] = 0
    for (let j = 0; j < n; ++j) {
      if (i === j) continue
      const s1 = words[i]
      const s2 = words[j]
      const minLen = Math.min(s1.length, s2.length)

      let k = minLen
      for (; k >= 0; --k) {
        if (s1.endsWith(s2.slice(0, k))) {
          break
        }
      }
      overlaps[i][j] = k
    }
  }

  //dp[i][j]表示当前单词的选择的状态为i(在这里把i当作bitset来用某一位为1就表示选择了words[i]),最后选择
  //的单词是j是，他们重叠部分能达到的最大长度
  const dp: number[][] = []
  //dp[i][j]只记录了重叠长度，我们还需要记录状态转移的路径，后面才能递推出答案
  //parent[i][j]表示dp[i][j]这个状态是从dp[i ^ (1 << j)][parent[i][j]]这个
  //状态转移过来的,也就是j之前选择的那个单词
  const parent: number[][] = []

  for (let i = 0; i < 1 << n; ++i) {
    dp[i] = Array.from<number>({ length: n }).fill(0)
    parent[i] = Array.from<number>({ length: n }).fill(-1)
  }

  for (let mask = 0; mask < 1 << n; ++mask) {
    for (let bit = 0; bit < n; ++bit) {
      //bit表示最后一次选择的单词，如果mask & (1 << bit) === 0表示最后一次没有选择任何单词
      //为非法状态，没法进行状态转移
      if ((mask & (1 << bit)) === 0) continue

      const pmask = mask ^ (1 << bit)

      //如果刨除掉bit已经为零了，就没办法由之前的状态转移过来了，所以这里就不用转移了
      if (pmask === 0) continue

      //j表示倒数第二次选择的单词
      for (let j = 0; j < n; ++j) {
        if ((mask & (1 << j)) === 0) continue
        //只有倒数第二次也选择了一个单词才能进行转移

        const val = dp[pmask][j] + overlaps[j][bit]

        if (val > dp[mask][bit]) {
          dp[mask][bit] = val
          parent[mask][bit] = j
        }
      }
    }
  }

  const seen: boolean[] = []
  let lastIndexOfMaxOverlap = 0
  const perm: number[] = []
  //找出目标组合中重叠部分最长的，lastIndexOfMaxOverlap存储了这个目标组合中最后一个元素的下标
  for (let i = 0; i < n; ++i) {
    if (dp[(1 << n) - 1][i] > dp[(1 << n) - 1][lastIndexOfMaxOverlap]) {
      lastIndexOfMaxOverlap = i
    }
  }

  //从最后的状态依次向前递推出完成的状态转移序列
  let p = lastIndexOfMaxOverlap
  let mask = (1 << n) - 1
  while (p !== -1) {
    seen[p] = true
    perm.push(p)
    const p2 = parent[mask][p]
    mask ^= 1 << p
    p = p2
  }

  const t = perm.length
  for (let i = 0; i < t >> 1; ++i) {
    const temp = perm[i]
    perm[i] = perm[t - i - 1]
    perm[t - i - 1] = temp
  }

  //上面的逻辑只有从前置状态转移过来的状态才会被放进序列，所以会漏掉一个初始状态
  //这里我们把这个初始状态加上
  for (let i = 0; i < n; ++i) {
    if (!seen[i]) perm.push(i)
  }

  let ans = words[perm[0]]

  for (let i = 1; i < n; ++i) {
    ans += words[perm[i]].slice(overlaps[perm[i - 1]][perm[i]])
  }

  return ans
}
