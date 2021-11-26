//leetcode 1055.形成字符串的最短路径
// 对于任何字符串，我们可以通过删除其中一些字符（也可能不删除）来构造该字符串的子序列。

// 给定源字符串 source 和目标字符串 target，找出源字符串中能通过串联形成目标字符串的子序列的最小数量。如果无法通过串联源字符串中的子序列来构造目标字符串，则返回 -1。

//

// 示例 1：

// 输入：source = "abc", target = "abcbc"
// 输出：2
// 解释：目标字符串 "abcbc" 可以由 "abc" 和 "bc" 形成，它们都是源字符串 "abc" 的子序列。
// 示例 2：

// 输入：source = "abc", target = "acdbc"
// 输出：-1
// 解释：由于目标字符串中包含字符 "d"，所以无法由源字符串的子序列构建目标字符串。
// 示例 3：

// 输入：source = "xyz", target = "xzyxz"
// 输出：3
// 解释：目标字符串可以按如下方式构建： "xz" + "y" + "xz"。

function shortestWay(source: string, target: string): number {
  let cur = 0
  const sLen = source.length
  const tLen = target.length
  let ans = 0
  let flag = true
  while (cur < tLen) {
    flag = true

    for (let i = 0; i < sLen; ++i) {
      if (source[i] === target[cur]) {
        ++cur
        flag = false
      }
    }
    ++ans
    //cur没有向前移动说明target[cur]这个字符,source里面没有直接退出循环
    if (flag) break
  }

  return flag ? -1 : ans
}
