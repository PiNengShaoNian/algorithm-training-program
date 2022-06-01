export function prisonAfterNDays(cells: number[], n: number): number[] {
  let state = 0
  for (let i = 0; i < 8; ++i) {
    state |= cells[i] << i
  }
  //记录该状态前一次出现的位置
  const seen = new Map<number, number>()

  const getNextDay = () => {
    let nextState = 0

    for (let i = 1; i <= 6; ++i) {
      if (((state >> (i - 1)) & 1) === ((state >> (i + 1)) & 1)) {
        nextState |= 1 << i
      }
    }

    return nextState
  }

  while (n > 0) {
    if (seen.has(state)) {
      //又遇到了该状态，这样的话我们就可以知道这个状态每经过seen.get(state) - n
      //个步骤又会回到自身，这样的话步骤中若干个这样长度的步进都是在做无用功，所以我们直接
      //在走n %= seen.get(state)! - n步也是一样的效果
      n %= seen.get(state)! - n
    }
    seen.set(state, n)

    if (n >= 1) {
      --n
      state = getNextDay()
    }
  }

  let ans: number[] = []

  for (let i = 0; i < 8; ++i) {
    if ((state & (1 << i)) > 0) {
      ans[i] = 1
    } else {
      ans[i] = 0
    }
  }

  return ans
}
