export function shortestSubarray(nums: number[], k: number): number {
    // 我来翻一下解答：
    // 首先解释P:
    // P[n]=sum(A[:n-1])
    // 举例： A = [2,-1,2]
    // P = [0, 2, 1, 3]
    // 如果我们想要A[1:3]的和，也就是[-1,2]的和，结果就是P[3]-P[1]=1
    // 队列维护：
    // 官方答案就是通过维持一个队列，从头到尾遍历。对于每个y，找出满足，P[y]-P[x]>=K的最大的x。如果y-x比之前的长度要小就记录新的最小值。
    // 维持队列涉及两个规则：
    // 对于新加入的y，前面的P[?]都要比新加入的P[y]要小，比P[y]大的P[?]都要pop掉，甚至如果都比P[y]大，整个队列都要清空。
    // 为什么？
    // 因为只有比P[y]小的P[?]，才能跟y组成，(y,x)组合，使得P[y]-P[x]>=K。那些不比P[y]小的P[?]，起不到任何作用，不可能存在一个x让当前的y或者之后的新y满足P[y]-P[x]>=K，也就不可能去更新最小长度。因此，只有比 P[y]小的P[?]才有保留的必要。
    
    // 为什么当队列里第一个x满足P[y]-P[x]>=K的时候，第一个x可以被pop掉？
    // 因为此时我们构成了一个P[y]-P[x]>=K，之后这个x就没有作用了。
    // 为什么这个x没有用了？
    // 因为即使之后存在某个其他的y'，也可以跟这个x构成P[y]-P[x]>=K，但是因为y'>y，因此次新的长度一定比当前的长度y-x要长，因为可以不用考虑。
  
    const deque: number[] = []
  const n = nums.length
  const presum: number[] = []
  presum[0] = 0

  for (let i = 0; i < n; ++i) {
    presum[i + 1] = presum[i] + nums[i]
  }

  let ans = Infinity

  for (let y = 0; y <= n; ++y) {
    while (deque.length && presum[deque[deque.length - 1]] > presum[y])
      deque.pop()
    // p[y] - p[x] >= k
    while (deque.length && presum[y] - presum[deque[0]] >= k) {
      ans = Math.min(ans, y - deque.shift()!)
    }
    deque.push(y)
  }

  return isFinite(ans) ? ans : -1
}
