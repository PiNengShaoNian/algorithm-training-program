import { ways } from '../number-of-ways-of-cutting-a-pizza'

test('number-of-ways-of-cutting-a-pizza', () => {
//   expect(ways(['A..', 'AA.', '...'], 3)).toBe(1)
//   expect(ways(['A..', 'AA.', 'A..'], 3)).toBe(2)
  expect(ways(['A..', 'AAA', '...'], 3)).toBe(3)
})
