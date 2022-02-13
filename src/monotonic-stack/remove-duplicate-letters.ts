function removeDuplicateLetters(s: string): string {
  const vis: boolean[] = []
  const count: number[] = Array.from<number>({ length: 26 }).fill(0)
  const n = s.length
  const stack: string[] = []
  for (const x of s) {
    ++count[x.charCodeAt(0) - 97]
  }

  for (let i = 0; i < n; ++i) {
    const charCode = s.charCodeAt(i) - 97

    //只考虑栈中没有出现过的字符，因为如果一个字符已经出现过在栈中
    //说明前面栈中有个字符他的字典序比该字符大但是应为他因为出现次数
    //的问题不在能被舍弃了，所以我们遇到一个已经出现在栈中的元素可以直接抛弃他
    //如果选择了该位置插入该元素只会使结果的字典序变大
    //考虑如下字符串"cbacdcbc"
    //在遍历到最后一个字符时，此时栈中的元素为[a,c,d,b]
    //此时遍历到的元素为c,但是我们发现栈中已经存在c了，这是应为d
    //的关系如果不是应为d不能被舍弃，前面的c早就被出栈了，这时我们
    //应该抛弃此时遍历到的c,应为选则在b后面插入c只会使结果更糟糕,
    //我们同时可以发现当遍历到字符串中第二个c的时候也是一样的情况,
    //在d后面插入c，而删除前面的c也只会使结果更糟糕
    if (!vis[charCode]) {
      while (stack.length && stack[stack.length - 1] > s[i]) {
        const lastCharCode = stack[stack.length - 1].charCodeAt(0) - 97
        //这个字符后续还会再出现，把他弹出栈是栈中元素以字典序排列
        if (count[lastCharCode] > 0) {
          vis[lastCharCode] = false
          stack.pop()
        }
        //这个字符后续不会在出现了，不把他弹出栈
        else break
      }

      vis[charCode] = true
      stack.push(s[i])
    }

    //没遇到一个字符就将他的次数减1当减为零的时候表示后面不会在出现该字符了
    --count[charCode]
  }

  return stack.join('')
}
