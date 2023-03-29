int rob1(int *nums, int numsSize)
{
    if (numsSize == 1)
        return nums[0];

    // dp[i]表示在只在区间dp[0:i]内偷窃的情况下能获得的最大收益
    int dp[numsSize];

#define MAX(a, b) (a) > (b) ? (a) : (b)

    dp[0] = nums[0];
    dp[1] = MAX(dp[0], nums[1]);
    for (int i = 2; i < numsSize; ++i)
    {
        dp[i] = MAX(nums[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[numsSize - 1];
}

int rob(int *nums, int numsSize)
{
    if (numsSize == 1)
        return nums[0];

    int case1 = rob1(nums + 1, numsSize - 1);
    int case2 = rob1(nums, numsSize - 1);
    return case1 > case2 ? case1 : case2;
}