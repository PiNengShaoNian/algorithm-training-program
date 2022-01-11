export function findTheLongestSubstring(s: string): number {
  const vowelToBit: Record<string, number> = {
    a: 1,
    e: 2,
    i: 4,
    o: 8,
    u: 16,
  }
  const bitsToIndex = new Map<number, number>()
  bitsToIndex.set(0, -1)
  let ans = 0
  let bits = 0

  for (let i = 0; i < s.length; ++i) {
    bits ^= vowelToBit[s[i]] ?? 0

    if (!bitsToIndex.has(bits)) {
      bitsToIndex.set(bits, i)
    } else {
      ans = Math.max(ans, i - bitsToIndex.get(bits)!)
    }
  }

  return ans
}
