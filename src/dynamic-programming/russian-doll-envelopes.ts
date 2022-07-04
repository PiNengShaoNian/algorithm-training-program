export function maxEnvelopes(envelopes: number[][]): number {
  //可以用最长递增子序列的思路去解题，但是那种思路是和顺序相关的
  //这种求套娃是和顺序无关的，所以我们可以先按宽度排序,将维度将维度
  //降为只有高度，在对信封做一遍最长递增子序列就行
  //注意：这里由于对于求解每个dp[i]时都会判断判断他前面的
  //dp[j](j < i)能不能接在dp[i]前面所以可以省去对高度的降序排序
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

  //我们先按照宽度按照升序排序，然后只剩下高度一个维度，然后就可以按照LIS的思路来解题了
  //这里有个细节考虑envelopes：[[1,1],[2,2],[2,3]]，根据题意只有宽高都大于的情况下才能
  //嵌套，所以[2,2]不能放进[2,3],但是如果只按照宽度进行升序排序，此时的高度形成的序列
  //就为[1,2,3]满足LIS的条件，但是实际最大的嵌套层数只能为2,此时如果我们再加入一个限制条件
  //在宽度相同的情况下，再按照高度降序排序此时高度组成的序列就为[1,3,2],此时计算出的答案就
  //是正确的，应为我们能保证，在宽度相同的所有信封我们最多只会挑出一个把他加入LIS中，这样
  //我们就能保证宽度相同的信封不会被重复假如，产生错误的答案
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

//树状数组解法
export function maxEnvelopes2(envelopes: number[][]): number {
  //将envelopes按照宽度排序后，问题就变成了在envelopes中以高度为唯一维度
  //寻找最长递增递增子序列,假设dp[i]为以envelopes[i]为结尾的最长递增子序列
  //那么要求出他，就找出[0,dp[i - 1]] + 1 中的最大值，现在问题就变成了寻找
  //[0,envelopes[i - 1]]区间中的区间最大值，因为区间的左端点一直都是0,就可以
  //使用树状数组这种求前缀操作的数据结构

  //高度很高但是实际的信封数量又比较少，可以通过离散化来减小数据规模
  const heightsSet = new Set<number>()
  for (let i = 0; i < envelopes.length; ++i) {
    heightsSet.add(envelopes[i][1])
  }
  const heights = Array.from(heightsSet.values()).sort((a, b) => a - b)
  const heightToIndex = new Map<number, number>()
  let idx = 0
  for (const h of heights) {
    heightToIndex.set(h, idx++)
  }
  const n = heightsSet.size
  const tree: number[] = Array.from<number>({ length: n + 1 }).fill(0)

  /**
   * 更新第x矮高度对应的最长递增子序列长度为val
   */
  const update = (x: number, val: number) => {
    for (; x <= n; x += x & -x) {
      tree[x] = Math.max(tree[x], val)
    }
  }

  /**
   *
   * @param x [0-n]，获取当前第x矮的高度能构成的最长递增子序列
   * @returns
   */
  const query = (x: number) => {
    let ans = 0

    for (; x > 0; x -= x & -x) {
      ans = Math.max(tree[x], ans)
    }

    return ans
  }

  envelopes.sort((a, b) => {
    if (a[0] !== b[0]) return a[0] - b[0]

    return b[1] - a[1]
  })

  let ans = 1
  for (const env of envelopes) {
    //i表示了env[1]为第几矮的高度
    //比如高度列表为[4,5,6]那么4对于的i就为1代表他是第一矮的高度写作i(4) = 1
    //6对应的i就为3代表他是低三矮的高度写为i(6) = 3,
    //那么要求以6结尾的最长递增子序列最可以求i(6) - 1也就是比他矮一位的高度
    //能构成的最长递增子序列再加1
    const i = heightToIndex.get(env[1])! + 1

    const pre = query(i - 1)
    ans = Math.max(pre + 1, ans)
    update(i, pre + 1)
  }

  return ans
}
