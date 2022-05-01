import { maxStudents } from '../maximum-students-taking-exam'

test('maxStudents', () => {
  expect(maxStudents([['.', '#', '.']])).toBe(2)
  expect(maxStudents([['.', '.', '.']])).toBe(2)
  expect(
    maxStudents([
      ['#', '.'],
      ['.', '#'],
    ])
  ).toBe(1)
})
