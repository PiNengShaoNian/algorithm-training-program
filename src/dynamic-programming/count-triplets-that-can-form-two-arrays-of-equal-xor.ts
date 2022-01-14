//时间复杂度O(N ^ 3)
export function countTriplets(arr: number[]): number {
  const prefix: number[] = []
  const n = arr.length
  prefix[0] = 0

  for (let i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] ^ arr[i]
  }

  let ans = 0
  for (let i = 0; i < n; ++i) {
    for (let j = i + 1; j < n; ++j) {
      for (let k = j; k < n; ++k) {
        if ((prefix[i] ^ prefix[j]) === (prefix[j] ^ prefix[k + 1])) {
          ++ans
        }
      }
    }
  }

  return ans
}

//时间复杂度O(N ^ 3),小优化
export function countTriplets1(arr: number[]): number {
  const prefix: number[] = []
  const n = arr.length
  prefix[0] = 0

  for (let i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] ^ arr[i]
  }

  let ans = 0
  for (let i = 0; i < n; ++i) {
    for (let j = i + 1; j < n; ++j) {
      for (let k = j; k < n; ++k) {
        //如果(prefix[i] ^ prefix[j]) === (prefix[j] ^ prefix[k + 1])成立
        //那么他的等价式子prefix[i] === prefix[k + 1]也成立
        if (prefix[i] === prefix[k + 1]) {
          ++ans
        }
      }
    }
  }

  return ans
}

//时间复杂度O(N ^ 2)
export function countTriplets2(arr: number[]): number {
  const prefix: number[] = []
  const n = arr.length
  prefix[0] = 0

  for (let i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] ^ arr[i]
  }

  let ans = 0
  for (let i = 0; i < n; ++i) {
    for (let k = i + 1; k < n; ++k) {
      //当prefix[i] === prefix[k + 1]成立时，
      //[i+1,k]之间的j全部都时符合要求的
      if (prefix[i] === prefix[k + 1]) {
        ans += k - i
      }
    }
  }

  return ans
}

//时间复杂度O(N)
export function countTriplets4(arr: number[]): number {
  const prefix: number[] = []
  const n = arr.length
  prefix[0] = 0

  for (let i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] ^ arr[i]
  }

  const count: Record<number, number> = {}
  const total: Record<number, number> = {}

  let ans = 0
  for (let k = 0; k < n; ++k) {
    if (count[prefix[k + 1]]) {
      ans += count[prefix[k + 1]] * k - total[prefix[k + 1]]
    }

    total[prefix[k]] = (total[prefix[k]] ?? 0) + k
    count[prefix[k]] = (count[prefix[k]] ?? 0) + 1
  }

  return ans
}
