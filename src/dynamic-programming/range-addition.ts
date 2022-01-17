export function getModifiedArray(n: number, updates: number[][]): number[] {
  const arr: number[] = Array.from<number>({ length: n }).fill(0)

  for (let i = 0; i < updates.length; ++i) {
    const [l, r, delta] = updates[i]
    arr[l] += delta
    if (r + 1 < n) arr[r + 1] -= delta
  }

  for (let i = 1; i < n; ++i) {
    arr[i] += arr[i - 1]
  }

  return arr
}
