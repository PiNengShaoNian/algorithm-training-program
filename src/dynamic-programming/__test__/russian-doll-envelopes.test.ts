import { maxEnvelopes1 } from '../russian-doll-envelopes'

test('maxEnvelopes1', () => {
  expect(
    maxEnvelopes1([
      [5, 4],
      [6, 4],
      [6, 7],
      [2, 3],
    ])
  ).toBe(3)

  expect(
    maxEnvelopes1([
      [30, 50],
      [12, 2],
      [3, 4],
      [12, 15],
    ])
  ).toBe(3)
})
