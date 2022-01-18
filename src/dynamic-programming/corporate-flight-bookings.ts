export function corpFlightBookings(bookings: number[][], n: number): number[] {
  const arr = Array.from<number>({ length: n }).fill(0)

  for (let i = 0; i < bookings.length; ++i) {
    const [l, r, delta] = bookings[i]
    arr[l - 1] += delta
    if (r < n) {
      arr[r] -= delta
    }
  }

  for (let i = 1; i < n; ++i) {
    arr[i] += arr[i - 1]
  }

  return arr
}
