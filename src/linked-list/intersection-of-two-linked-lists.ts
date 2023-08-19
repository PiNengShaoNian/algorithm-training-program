declare type ListNode = any

export function getIntersectionNode(
  headA: ListNode | null,
  headB: ListNode | null
): ListNode | null {
  const stack1: ListNode[] = []
  const stack2: ListNode[] = []

  let curr = headA
  while (curr) {
    stack1.push(curr)
    curr = curr.next
  }

  curr = headB
  while (curr) {
    stack2.push(curr)
    curr = curr.next
  }

  let ans = null
  while (stack1.length && stack2.length) {
    const a = stack1.pop()
    const b = stack2.pop()

    if (a === b) {
      ans = a
      continue
    } else {
      break
    }
  }

  return ans
}
