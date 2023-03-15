int lengthOfLIS(int *nums, int numsSize)
{
    int *dp = malloc(numsSize * sizeof(int));
    dp[0] = 1;
    int ans = 1;
#define MAX(a, b) (a) > (b) ? (a) : (b)
    for (int i = 1; i < numsSize; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = MAX(dp[i], dp[j] + 1);
            }
        }

        ans = MAX(dp[i], ans);
    }

    return ans;
}

int lengthOfLIS(int *nums, int numsSize)
{
    // 通过二分查找插入位置动态构建出来的最长递增子序列
    // tails[i]表示长度为i的最长递增子序列，该序列最后的一个数字的最小值为tails[i]
    int *tails = (int *)malloc((numsSize + 1) * sizeof(int));
    int len = 1;
    tails[1] = nums[0];

    for (int i = 1; i < numsSize; ++i)
    {
        if (nums[i] > tails[len])
        {
            tails[++len] = nums[i];
        }
        else
        {
            // 左边从1开始tails[0]为未定义行为
            int l = 1, r = len, pos = 0;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (tails[mid] < nums[i])
                {
                    pos = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            tails[pos + 1] = nums[i];
        }
    }

    free(tails);
    return len;
}