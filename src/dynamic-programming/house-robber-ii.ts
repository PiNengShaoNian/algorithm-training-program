export function rob(nums: number[]): number {
  //和打家劫舍一的思路类似，不过这次房子是首尾相连的，意味着偷了第一间房子
  //就不能偷最后一间房子，反之亦然,那我们就把问题分为两个子问题，
  //(1)只在[1, n]的范围内偷,(2)只在[0,n - 1]范围内偷
  //然后再在取这两个区间里的最大者即可
  if (nums.length === 1) return nums[0]
  if (nums.length === 2) return Math.max(nums[0], nums[1])

  //dp1[i]表示只偷[0,i]区间内房子能获得的最大收益,其中0 <= i < nums.length - 1
  const dp1: number[] = [nums[0], Math.max(nums[0], nums[1])]

  //偷盗范围包含了第一间房子那就不能包含最后一间,
  for (let i = 2; i < nums.length - 1; ++i) {
    dp1[i] = Math.max(dp1[i - 1], dp1[i - 2] + nums[i])
  }

  //偷盗范围包含了最后一间房子那就不能包含第一间房子
  //1 <= i < nums.length
  const dp2: number[] = [0, nums[1], Math.max(nums[1], nums[2])]

  for (let i = 3; i < nums.length; ++i) {
    dp2[i] = Math.max(dp2[i - 1], dp2[i - 2] + nums[i])
  }

  return Math.max(dp1[nums.length - 2], dp2[nums.length - 1])
}
