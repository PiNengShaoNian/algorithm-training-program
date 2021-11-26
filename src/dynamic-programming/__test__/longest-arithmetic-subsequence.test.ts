import { longestArithSeqLength } from '../longest-arithmetic-subsequence'

test('longestArithSeqLength', () => {
  expect(longestArithSeqLength([1, 7, 5, 9, 14, 2, 3, 21])).toBe(3)
  //0 6 8 9
  expect(longestArithSeqLength([6, 5, 10, 48, 49, 21, 7, 9, 8, 9])).toBe(4)
})
