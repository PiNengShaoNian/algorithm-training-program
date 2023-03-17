int findNumberOfLIS(int *nums, int numsSize)
{
    int count[numsSize];
    int dp[numsSize];

    dp[0] = 1;
    count[0] = 1;

    int maxLen = 1;
    int ans = 1;

    for (int i = 1; i < numsSize; ++i)
    {
        dp[i] = 1;
        count[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (nums[j] < nums[i])
            {
                if (dp[j] + 1 == dp[i])
                {
                    count[i] += count[j];
                }
                else if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }
            }
        }

        if (maxLen == dp[i])
        {
            ans += count[i];
        }
        else if (dp[i] > maxLen)
        {
            maxLen = dp[i];
            ans = count[i];
        }
    }

    return ans;
}