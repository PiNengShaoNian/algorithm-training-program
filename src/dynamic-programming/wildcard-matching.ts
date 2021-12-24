function isMatch(s: string, p: string): boolean {
  const n = s.length
  const m = p.length

  //dp[i][j]为true表示s中前i个字符构成的子串和p中前j个字符构成的模式串
  //能够匹配，为false则表示不能匹配,其中i和j都从1开始，为0时表示为空串
  const dp: boolean[][] = []

  for (let i = 0; i <= n; ++i) {
    dp[i] = []
  }

  //空字符串和空模式串匹配
  dp[0][0] = true
  //开头连续的*好能和空字符串匹配
  for (let i = 1; i <= m && p[i - 1] === '*'; ++i) dp[0][i] = true

  for (let i = 1; i <= n; ++i) {
    for (let j = 1; j <= m; ++j) {
      if (s[i - 1] === p[j - 1] || p[j - 1] === '?') {
        //当s[i - 1]和p[j - 1]相等或者p[j - 1]等于问号时，dp[i][j]等于
        //dp[i - 1][j - 1]的匹配情况
        dp[i][j] = dp[i - 1][j - 1]
      } else if (p[j - 1] === '*') {
        dp[i][j] =
          //这个星号选择匹配若干个字符则
          // dp[i][j] = dp[i-1][j] || dp[i-2][j] || dp[i-3][j] || ...|| dp[0][j]，
          // dp[i-1][j] = dp[i-2][j] || dp[i-3][j] || ...|| dp[0][j]，
          // dp[i][j] ==> dp[i-1][j]
          //考虑如下情况
          //s = hello
          //p = he*
          //i = 5, j = 3
          //在最后一个星号选择若干字符的情况下
          //dp[5][3] = dp[5 - 1][3] || dp[5 - 2][3] || dp[5 - 3][3] || dp[5 - 4][3] || dp[5 - 5][3]
          //dp[5][3] = dp[4][3] || dp[3][3] || dp[2][3] || dp[1][3] || dp[0][3]
          //不难看出dp[2][2] = true，因为`he`是s和p的公共前缀
          //又因为dp[2][3] = dp[2 - 1][3] || dp[2 - 2][3] || dp[2][2](星号选择不匹配字符)
          //   所以dp[2][3] = true
          //同理dp[3][3],dp[4][3],dp[5][3]都为true
          dp[i - 1][j] ||
          //这个星号选择什么都不匹配，匹配结构就等于dp[i][j - 1]
          dp[i][j - 1]
      }
    }
  }

  return !!dp[n][m]
}

//贪心解法
export function isMatch1(s: string, p: string): boolean {
  //由于连续的星号的作用等价于一个星号
  //所以把模式串看成这样的一个串 `*u1*u2*u3*...un*`
  //问题就变成在s中去找是否存在顺序的u1,u2,u3,...,un这样的字串

  const charMatch = (a: string, b: string): boolean => {
    return a === b || b === '?'
  }

  const allStars = (l: number, r: number): boolean => {
    for (let i = l; i < r; ++i) {
      if (p[i] !== '*') return false
    }

    return true
  }

  //当前s遍历到的位置
  let sIndex = 0
  //当前p遍历到的位置
  let pIndex = 0
  let sLen = s.length
  let pLen = p.length

  //特殊处理末尾不是星号的情况，一直裁剪末尾字符直到遇到一个星号
  while (pLen && sLen && p[pLen - 1] !== '*') {
    if (charMatch(s[sLen - 1], p[pLen - 1])) {
      --pLen
      --sLen
    } else {
      return false
    }
  }

  if (!pLen) {
    return !sLen
  }

  //字串ui在s中的起点
  let sRecord = -1
  //字串ui在p中的起点
  let pRecord = -1

  while (sIndex < sLen && pIndex < pLen) {
    if (p[pIndex] === '*') {
      //遇到了一个星号，记录新的u_i起点
      ++pIndex
      pRecord = pIndex
      sRecord = sIndex
    } else if (charMatch(s[sIndex], p[pIndex])) {
      ++sIndex
      ++pIndex
    } else if (sRecord !== -1 && sRecord + 1 < sLen) {
      //该字符不能匹配，那就让前面的星号吃掉他,u_i字串的范围从原来的[sRecord, x]
      //变成[sRecord + 1, x],注意x是不确定的只有遇到了下一个星号才直到
      sRecord += 1
      sIndex = sRecord
      //让pIndex复位重新开始尝试
      pIndex = pRecord
    } else {
      //这里处理了模式串开头不为星号的情况
      //s = abc
      //p = def
      //sIndex = 0,pIndex = 0
      //因为charMatch(s[0],p[0])返回false,并且sReocrd = -1
      //这里会直接返回false
      //当然如果尝试过了所有位置也找不到字串u_i也会进入到这里
      return false
    }
  }

  //考虑如下情况
  // s = abc
  // p = ab*d*
  //这种情况下前面的前缀ab会被首先匹配掉
  // s = c
  // p = *d*
  //遇到了星号，pIndex + 1,sIndex不变
  // s = c
  // p = d*
  // 然后c和d不匹配，选择用d前面的星号把c吃了
  // s = ""
  // p = d*
  // sIndex到达末尾退出循环，只有p中剩余的全部是星号才算匹配上了
  return allStars(pIndex, pLen)
}
