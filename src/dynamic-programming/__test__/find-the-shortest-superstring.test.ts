import { shortestSuperstring } from '../find-the-shortest-superstring'

test('shortestSuperstring', () => {
  expect(shortestSuperstring(['ctaagt', 'atgcatc'])).toBe('atgcatctaagt')
  expect(shortestSuperstring(['catg', 'atgcatc'])).toBe('catgcatc')
  expect(shortestSuperstring(['catg', 'ttca', 'atgcatc'])).toBe('ttcatgcatc')
})
