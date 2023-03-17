int maxSubArray(int *nums, int numsSize)
{
    int *dp = malloc(sizeof(int) * numsSize);

    int ans = nums[0];
    dp[0] = nums[0];
    for (int i = 1; i < numsSize; ++i)
    {
        dp[i] = nums[i];

        if (dp[i - 1] + nums[i] > nums[i])
        {
            dp[i] = dp[i - 1] + nums[i];
        }

        ans = ans > dp[i] ? ans : dp[i];
    }

    return ans;
}

int maxSubArray(int *nums, int numsSize)
{
    int *presum = malloc(sizeof(int) * (numsSize + 1));

    presum[0] = 0;
    for (int i = 1; i <= numsSize; ++i)
    {
        presum[i] = presum[i - 1] + nums[i - 1];
    }

    int presumMin = 0;
    int ans = nums[0];
    for (int i = 1; i <= numsSize; ++i)
    {
        ans = presum[i] - presumMin > ans ? presum[i] - presumMin : ans;

        presumMin = presum[i] < presumMin ? presum[i] : presumMin;
    }

    return ans;
}